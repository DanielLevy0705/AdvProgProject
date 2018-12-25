//
// Created by elronbandel on 12/23/18.
//

#ifndef IFCOMMAND_H
#define IFCOMMAND_H

#include "Expression.h"
#include "Expressioner.h"
#include "CommandSet.h"
#include "BoolExpression.h"
#include "ConditionExpression.h"
#include "SetExpression.h"

class IfCommand: public Expression {
    Expressioner* expressioner;

public:

    IfCommand(Expressioner* exprer) {
        expressioner = exprer;
    }

    double calculate()  const override {
        if (typeid((*(expressioner->next()))) == typeid(ConditionExpression)) {
            bool condition = expressioner->popNext()->calculate();
            Expression* exp = expressioner->popNext();
            if (condition) {
                if (typeid(*exp) == typeid(CommandSet)) {
                    exp->calculate();
                } else {
                    cout << "Error: no commands set inside { } after 'if'." <<endl;
                    exp->calculate();
                }
            }else if (typeid(*exp) != typeid(CommandSet)) {
                exp->calculate();
            }
        }
    }

    string getString() const override {
        return "if";
    }
};

#endif //UNTITLED4_IFCOMMAND_H
