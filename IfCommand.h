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
    CommandSet* commandSet;



    IfCommand(Expressioner* exprer) {
        expressioner = exprer;
    }

public:
    double calculate()  const override {
        if (typeid((*(expressioner->next()))) == typeid(ConditionExpression)) {
            if (expressioner->popNext()->calculate()) {
                if (typeid(*expressioner->popNext()) == typeid(StartSetExpression)) {
                   // commandSet = expressioner->getCommandSet();
                }
            }
        }
    }
};

#endif //UNTITLED4_IFCOMMAND_H
