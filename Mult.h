//
// Created by fatuity on 12/18/18.
//

#ifndef PROJ1_MULT_H
#define PROJ1_MULT_H


#include "Expression.h"
#include "MathExpression.h"

class Mult : public MathExpression {
    Expression *leftExp, *rightExp;
    string strRep;
public:
    Mult(string strVal,Expression *left, Expression *right) {
        leftExp = left;
        rightExp = right;
        strRep = strVal;
    }

    virtual double calculate() const {
        return leftExp->calculate() * rightExp->calculate();
    }

};


#endif //PROJ1_MULT_H
