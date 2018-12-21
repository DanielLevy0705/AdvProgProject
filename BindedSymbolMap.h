//
// Created by elronbandel on 12/20/18.
//

#ifndef BINDEDSYMBOLMAP_H
#define BINDEDSYMBOLMAP_H
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <pthread.h>
#include <string>
#include <map>
#include <list>
#include <iostream>
#include <vector>
#include <sstream>
#include "Value.h"
#include "LocalValue.h"

#define MAX_CONNEDTED_CLIENTS 5
#define FAILED -1
#define BUFFER_SIZE 1024
using  namespace std;
static vector<string> split(const string& s, char delimiter){
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
string getInnerString(char start,string s, char end)  {
    bool rec = false;
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == end && rec)
            return res;
        if (rec)
            res = res + s[i];
        if (s[i] == start)
            rec = true;
    }
}
typedef struct sockaddr_in Address;
typedef struct ServerConfig
{
    int port;
    int frequency;
    map<string, Value*>* symbolMap;
    bool* active;
} ServerConfig;
void* startUpdatesServer(void* serverConfig) {
    ServerConfig* config = (ServerConfig*)serverConfig;
    if (config != nullptr) {
        map<string, Value*>* symap = config->symbolMap;
        int port = config->port;
        int frequency = config->frequency;
        bool* active = config->active;
        delete serverConfig;
        //now actually opening the server
        Address serverAddress;
        socklen_t servAddrLen = sizeof(serverAddress);
        // create socket point
        int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket == FAILED)
            throw "Error: socket opening failed";
        /* Initialize socket structure */
        bzero((char *) &serverAddress, sizeof(serverAddress));
        //address
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = INADDR_ANY;
        serverAddress.sin_port = htons(port);
        //bind the host adress using bind
        if (bind(serverSocket, (struct sockaddr*)&serverAddress, servAddrLen) == FAILED)
            throw "Error: socket binding failed";
        //start listening to incoming connections
        listen(serverSocket, MAX_CONNEDTED_CLIENTS);
        //main routine loop of collecting clients
        //define the client sockets structure
        int clientSocket;
        Address clientAdress;
        socklen_t cliAddrLen = sizeof(clientAdress);
        //look for clients
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAdress, &cliAddrLen);
        if (clientSocket == FAILED)
            throw "Error: client socket failed";

        char buffer[BUFFER_SIZE];
        vector<string> lines;

        //while this thread should be active try and get info from client
        while(*active) {
            if (read(clientSocket,buffer, BUFFER_SIZE) != FAILED) {
                string packet = getInnerString('{', buffer,'}');
                lines = split(packet,'\n');
                for (auto& line: lines){   //if its adress of variable
                     //split to pair
                    vector<string> pair = split(line,',');
                    //put the pair in the symbol map
                    if (!symap->count(pair[0]))  {
                        (*symap)[pair[0]] = new LocalValue(stod(pair[1]));
                    }  else {
                         *(*symap)[pair[0]] = stod(pair[1]);
                    }
                }
                usleep(1000/frequency);
            };
        }
        //finish the connsction
        close(clientSocket);
        close(serverSocket);
    }
    return nullptr;
}

class BindedSymbolMap {
    map<string, Value*>* symbolMap;
    //server-client members
    pthread_t serverThread, clientThread;
    bool serverActive = false;

public:
    BindedSymbolMap () {
        symbolMap = new map<string, Value*>;
    }
    void openDataServer(int port, int frequency) {
        ServerConfig* config = new ServerConfig();
        //give the server all the things it needs to update the symbol map
        config->port = port;
        config->frequency = frequency;
        config->active = &serverActive;
        config->symbolMap = symbolMap;
        //start the thread of the server
        serverActive = true;
       
       if (pthread_create(&serverThread, nullptr, startUpdatesServer, config))
            throw "Error: failed creating pthred";
    }
    void close() {
        pthread_cancel(serverThread);
    }
    Value*& operator [] (const string& key) {
        return (*symbolMap)[key];
    }
    ~BindedSymbolMap() {
        for (auto& valuePointer : *symbolMap) {
            delete(valuePointer.second);
        }
        delete symbolMap;
    }
};

#endif //BINDEDSYMBOLMAP_H
