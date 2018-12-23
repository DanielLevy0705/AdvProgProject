//
// Created by fatuity on 12/22/18.
//

#ifndef PROJ1_NEG_H
#define PROJ1_NEG_H


#include "Expression.h"
#include "MathExpression.h"

class Neg : public MathExpression {
    Expression* expression;
    string strVal;
public:
    Neg(string stringVal, Expression* exp) {
        expression = exp;
        strVal = stringVal;
    }

    virtual double calculate() const {
        return -expression->calculate();
    }

};


#endif //PROJ1_NEG_H
