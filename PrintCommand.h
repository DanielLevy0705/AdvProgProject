//
// Created by elronbandel on 12/23/18.
//

#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H

#include <iostream>
#include "Expressioner.h"
#include "Command.h"

using namespace std;

class PrintCommand : public Command {

    Expressioner *expressioner;

public:

    explicit PrintCommand(Expressioner *expr) {
        expressioner = expr;
    }

    double execute() const override {

        while (expressioner->argumentsInLine() > 0) {
            cout << expressioner->popNext()->getString();
            cout << " ";
        }
        cout << endl;
        return 0;
    }

    string getString() const override {
        return "print";
    }

};


#endif //UNTITLED4_PRINTCOMMAND_H
