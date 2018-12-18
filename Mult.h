//
// Created by fatuity on 12/18/18.
//

#ifndef PROJ1_MULT_H
#define PROJ1_MULT_H


#include "Expression.h"

class Mult : public Expression {
    Expression *leftExp, *rightExp;

    Mult(Expression *left, Expression *right) {
        leftExp = left;
        rightExp = right;
    }

    virtual double calculate() {
        return leftExp->calculate() * rightExp->calculate();
    }
};


#endif //PROJ1_MULT_H
