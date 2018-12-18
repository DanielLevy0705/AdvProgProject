#ifndef PROJ1_PLUS_H
#define PROJ1_PLUS_H


#include "Expression.h"

class Plus : public Expression {
    Expression *leftExp, *rightExp;
public:
    Plus(Expression *left, Expression *right) {
        leftExp = left;
        rightExp = right;
    }

    virtual double calculate() {
        return leftExp->calculate() + rightExp->calculate();
    }
};


#endif //PROJ1_PLUS_H
