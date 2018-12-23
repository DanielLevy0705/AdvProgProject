//
// Created by fatuity on 12/23/18.
//

#ifndef UNTITLED4_CONDITIONEXPRESSION_H
#define UNTITLED4_CONDITIONEXPRESSION_H


#include "Expression.h"

class ConditionExpression : public Expression {
    Expression *leftExp, *rightExp;
    string strVal;
public:
    virtual double calculate() const = 0;

    virtual string getString() const {
        return strVal;
    }

    virtual void print(ostream &out) const {
        if (calculate() != 0) {
            out << "true";
        } else {
            out << "false";
        }
    }
};


#endif //UNTITLED4_CONDITIONEXPRESSION_H
