//
// Created by elronbandel on 12/23/18.
//

#ifndef IFCOMMAND_H
#define IFCOMMAND_H

#include "Expression.h"
#include "Expressioner.h"
#include "CommandSet.h"
#include "BoolExpression.h"

class IfCommand: public Expression {
    Expressioner* expressioner;


    IfCommand(Expressioner* exprer) {
        expressioner = exprer;
    }

public:
    double calculate() const override {
        if (typeid((*(expressioner->next()))) == typeid(BoolExpression)) {
            if (expressioner->popNext()->calculate()) {
                if (typeid(*expressioner->next()) == typeid(CommandSet)) {
                    expressioner->popNext()->calculate();
                }
            }
        }
    }
};

#endif //UNTITLED4_IFCOMMAND_H
