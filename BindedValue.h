//
// Created by elronbandel on 12/20/18.
//

#ifndef BINDEDVALUE_H
#define BINDEDVALUE_H

#include "Value.h"
#include "BindedSymbolMap.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <string.h>
#define FAILED -1
#define MAX_CHARS_READ 256
typedef struct Info {
    int serverPort;
    string serverIp;
    string msg;

} Info;
void* sendAsClient(void* arg) {
    Info* info = (Info*) arg;
    //connect to server and update:
    struct sockaddr_in serverAddress;
    socklen_t addressLen = sizeof(serverAddress);
    struct hostent *server = gethostbyname(info->serverIp.c_str());
    if (server == NULL)
        throw "Error: failed finding the host";
    bzero((char *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serverAddress.sin_addr.s_addr, server->h_length);
    serverAddress.sin_port = htons(info->serverPort);
    //create socket to connect client to server
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == FAILED)
        throw "Error: failed to open client socket";
    if (::connect(clientSocket,(struct sockaddr*)&serverAddress, addressLen) == FAILED)
        throw "Error: client failed to connect to server";
    const char* buffer = info->msg.c_str();
    //write massage to server
    if (write(clientSocket, buffer, info->msg.size()) == FAILED)
        throw "Error: failed to send to server";
    close(clientSocket);
    delete(info);
    pthread_exit(nullptr);
}
using namespace std;
class BindedValue : public Value {
    string path;
    BindedSymbolMap* symap;
    string serverIP;
    int serverPort;

public:
    BindedValue(const string& pth, BindedSymbolMap* symbolMap, const string& srvrIp, int srvrPort) {
        path = pth;
        symap = symbolMap;
        serverIP = srvrIp;
        serverPort = srvrPort;
    }
    void operator = (double num) {
        string command = "set " + path + " " + to_string(num);
        Info* info = new Info();
        info->serverIp = serverIP;
        info->serverPort = serverPort;
        info->msg = command;
        //send command to server to set value in diffrent thread
        pthread_t clientThread;
        pthread_create(&clientThread, nullptr, sendAsClient, info);
    }
    operator double() {
        return *(*symap)[path];
    }
};

#endif //BINDEDVALUE_H
