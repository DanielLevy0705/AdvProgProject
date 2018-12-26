//
// Created by elronbandel on 12/25/18.
//

#ifndef WHILECOMMAND_H
#define WHILECOMMAND_H

#include "Command.h"
#include "Expressioner.h"
#include "CommandSet.h"
#include "ConditionExpression.h"
#include "SetExpression.h"
#include "Expointer.h"

class WhileCommand : public Command {
    Expressioner *expressioner;

public:

    WhileCommand(Expressioner *exprer) {
        expressioner = exprer;
    }

    double execute() const override;

    string getString() const override {
        return "while";
    }
};

#endif //UNTITLED4_WHILECOMMAND_H
