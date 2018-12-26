//
// Created by elronbandel on 12/26/18.
//

#ifndef SLEEPCOMMAND_H
#define SLEEPCOMMAND_H

#include "Expressioner.h"
#include "Command.h"
#include "ValueExpression.h"

using namespace std;

class SleepCommand : public Command {

    Expressioner *expressioner;

public:

    explicit SleepCommand(Expressioner *expr) {
        expressioner = expr;
    }

    double execute() const override {
        usleep(expressioner->popNext()->calculate());
        return 0;
    }

    string getString() const override {
        return "sleep";
    }

};

#endif //UNTITLED4_SLEEPCOMMAND_H
