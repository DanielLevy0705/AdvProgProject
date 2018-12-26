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
    BindedSymbolMap* symap;
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
        info->symap->sendAsClient(info->bindedValue->getSetString(info->num).c_str() );
        pthread_exit(nullptr);
    }

    void operator = (double num) {
        if (path[0] == '/') {
            Info* info = new Info();
            info->bindedValue = this;
            info->num = num;
            info->symap = symap;
            //send command to server to set value in diffrent thread
            pthread_t clientThread;
            pthread_create(&clientThread, nullptr, sendAsClient, info);
        } else {
            *((*symap)[path]) = num;
        }

    }

    string getSetString(double num) {
        return string("set " + path + " " + to_string(num) + "\r\n");
    }

    operator double() {
        return *(*symap)[path];
    }

    operator string() {
        return (string)*(*symap)[path];
    }


};

#endif //BINDEDVALUE_H
