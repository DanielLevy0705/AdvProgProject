//
// Created by fatuity on 12/22/18.
//

#ifndef PROJ1_NEG_H
#define PROJ1_NEG_H


#include "Expression.h"

class Neg : public Expression {
    Expression expression;
    string strVal;
public:
    Neg(string stringVal, Expression* exp) {
        expression = exp;
        strVal = stringVal;
    }

    double calculate() {
        return -expression.calculate();
    }

    string getString() {
        return strVal;
    }
};


#endif //PROJ1_NEG_H
