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
#include "Value.h"

#define MAX_CONNEDTED_CLIENTS 5
#define FAILED -1
#define BUFFER_SIZE 256
using  namespace std;
enum StandartParameters{GEAR, SPEED};
typedef struct sockaddr_in Address;
typedef struct ServerConfig
{
    int port;
    int frequency;
    map<string, Value>* symbolMap;
    bool* active;
} ServerConfig;
void* startUpdatesServer(void* serverConfig) {
    ServerConfig* config = (ServerConfig*)serverConfig;
    if (config != nullptr) {
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
        serverAddress.sin_port = htons(config->port);
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
        //while this thread should be active try and get info from client
        while(*config->active) {
            if (recv(serverSocket, buffer, BUFFER_SIZE, 0) == FAILED)
                throw "Error: failed to read from server"
            list<string> parmeters = split(buffer,',');
                //here we need to get every single one of them and push it to map as
                //local value with name which is the adress in the flightgear server

            sleep(config->frequency);
        }
        //finish the connsction
        close(clientSocket);

    }
    return nullptr;
}

class BindedSymbolMap {
    map<string, Value> symbolMap;
    //server-client members
    pthread_t serverThread, clientThread;
    bool serverActive = false;




public:
    void openDataServer(int port, int frequency) {
        ServerConfig config;
        //give the server all the things it needs to update the symbol map
        config.port = port;
        config.frequency = frequency;
        config.active = &serverActive;
        config.symbolMap = &symbolMap;
        //start the thread of the server
        serverActive = true;
        pthread_create(&serverThread, nullptr, startUpdatesServer, &config);
    }

    void close() {
        pthread_cancel(serverThread);
    }
    Value& operator [] (const string& key) {
        return symbolMap[key];
    }
};

#endif //BINDEDSYMBOLMAP_H
