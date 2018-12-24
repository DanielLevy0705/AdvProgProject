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
class BindedValue;
typedef struct Info {
    BindedValue* bindedValue;
    double num;

} Info;

using namespace std;
class BindedValue : public Value {
    string path;
    BindedSymbolMap* symap;

public:
    BindedValue(const string& pth, BindedSymbolMap* symbolMap) {
        path = pth;
        symap = symbolMap;
    }
    static void* sendAsClient(void* arg) {
        Info* info = (Info*)arg;
        //write massage to server
        info->bindedValue->sendToServer( info->bindedValue->getSetString(info->num) );
        pthread_exit(nullptr);
    }

    void operator = (double num) {
        Info* info = new Info();
        info->bindedValue = this;
        info->num = num;
        //send command to server to set value in diffrent thread
        pthread_t clientThread;
        pthread_create(&clientThread, nullptr, sendAsClient, info);

    }

    string getSetString(double num) {
        return string("set " + path + " " + to_string(num) + "\r\n");
    }

    void sendToServer(const string& msg) {
        if (send(symap->getClientSocket(), msg.c_str(), msg.size(),0) == FAILED)
            cout<< "Error: failed to send to server" << endl;

    }
    operator double() {
        return *(*symap)[path];
    }

    operator string() {
        return (string)*(*symap)[path];
    }


};

#endif //BINDEDVALUE_H
