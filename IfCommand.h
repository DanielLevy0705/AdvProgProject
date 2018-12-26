//
// Created by elronbandel on 12/23/18.
//

#ifndef IFCOMMAND_H
#define IFCOMMAND_H

#include "Command.h"
#include "Expressioner.h"
#include "CommandSet.h"
#include "ConditionExpression.h"
#include "SetExpression.h"

class IfCommand: public Command {
    Expressioner* expressioner;

public:

    IfCommand(Expressioner* exprer) {
        expressioner = exprer;
    }

    double execute()  const override {
        if ((expressioner->next()->getType()) == typeid(ConditionExpression)) {
            bool condition = expressioner->popNext()->calculate();
            Expression* exp = expressioner->popNext();
            if (condition) {
                if (exp->getType() == typeid(CommandSet)) {
                    exp->calculate();
                } else {
                    cout << "Error: no commands set inside { } after 'if'." <<endl;
                    exp->calculate();
                }
            }else if (exp->getType() != typeid(CommandSet)) {
                exp->calculate();
            }
        }
    }

    string getString() const override {
        return "if";
    }
};

#endif //UNTITLED4_IFCOMMAND_H
