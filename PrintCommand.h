//
// Created by elronbandel on 12/23/18.
//

#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H

#include <iostream>
#include "Expression.h"
#include "Expressioner.h"
using namespace std;

class PrintCommand: public Expression{

    Expressioner* expressioner;

public:

    explicit PrintCommand(Expressioner* expr) {
        expressioner = expr;
    }

    double calculate() override {

        while (expressioner->argumentsInLine() > 0) {
            string expStr = expressioner->popNext()->getString();
            cout << expStr;
        }
        cout << endl;
        return 0;
    }

    string getString() override {
        return "print";
    }
};


#endif //UNTITLED4_PRINTCOMMAND_H
