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
string getInnerString(char start, const string& s, char end);

typedef struct sockaddr_in Address;


class BindedSymbolMap {
    map<string, Value*>* symbolMap;
    //server-client members
    pthread_t serverThread, clientThread;
    bool* updatesThreadActive;
    int updatesServerSocket;
    int clientSocket;
    int updatesSocket;
    int updatesFrequency; //how many time a second should be updated
    pthread_mutex_t updatsMutex;
    vector<string> paths;
    bool connectedAsClient;



private:


    void openServerAndGetClient(int port);
    static void* startUpdatesRoutine(void* serverConfig);
public:
    //constructor
    BindedSymbolMap (vector<string> pats) {
        paths = pats;
        symbolMap = new map<string, Value*>;
        updatesThreadActive = new bool(false); //the
       clientSocket = FAILED;
       updatesSocket = FAILED;
       updatesServerSocket = FAILED;
        updatsMutex = PTHREAD_MUTEX_INITIALIZER;
    }


    //external function to open the data server
    void openDataServer(int port, int frequency);


    void close() {
        *updatesThreadActive = false;
        if(updatesSocket != FAILED)
            ::close(updatesSocket);
        if(clientSocket != FAILED)
            ::close(clientSocket);
        if(clientSocket != FAILED);
            ::close(updatesServerSocket);
    }
    void connect(const string& ip, int port);
    int getClientSocket() {
        return clientSocket;
    }
    bool canBind() {
        return connectedAsClient;
    }
    void updateTable();
    bool isUpdatesActive() {
        return updatesThreadActive;
    }
    void waitBetweenUpdates();
    bool exist(const string& name) {
        bool res = (symbolMap->find(name) != symbolMap->end());;
        return  res;
    }

    void sendAsClient(const char* msg) {
        if (::write(clientSocket, msg, strlen(msg)) <= FAILED)
            cout<< "Error: failed to send to server." << endl;
    }

    void set(const string& key, Value* val) {
        if ((*symbolMap)[key] != nullptr)
            delete (*symbolMap)[key];
        (*symbolMap)[key] = val;
    }
    void set(const string& key, double value) {
        *(*symbolMap)[key] = value;
    }

    Value*& operator [] (const string& key) {
        return (*symbolMap)[key];
    }
    ~BindedSymbolMap() {
        close();
        for (auto& valuePointer : *symbolMap) {
            delete(valuePointer.second);
        }
        delete symbolMap;
        delete updatesThreadActive;
    }
};

#endif //BINDEDSYMBOLMAP_H
