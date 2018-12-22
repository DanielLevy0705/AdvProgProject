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


    void openServerAndGetClient(int port);
    static void* startUpdatesRoutine(void* serverConfig);
public:
    //constructor
    BindedSymbolMap () {
        symbolMap = new map<string, Value*>;
        updatesThreadActive = new bool(false); //the
        updatsMutex = PTHREAD_MUTEX_INITIALIZER;
    }
    //external function to open the data server
    void openDataServer(int port, int frequency);


    void close() {
        *updatesThreadActive = false;
        ::close(updatesSocket);
        ::close(clientSocket);
        ::close(updatesServerSocket);
    }
    void connect(const string& ip, int port);
    int getClientSocket() {
        return clientSocket;
    }
    void updateTable();
    bool isUpdatesActive() {
        return updatesThreadActive;
    }
    void waitBetweenUpdates();
    bool exist(const string& name) {
        return (symbolMap->count(name) > 0);
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
