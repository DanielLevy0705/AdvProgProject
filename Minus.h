#ifndef PROJ1_MINUS_H
#define PROJ1_MINUS_H


#include "Expression.h"

class Minus : public Expression {
    Expression *leftExp, *rightExp;
public:
    Minus(Expression *left, Expression *right) {
        leftExp = left;
        rightExp = right;
    }

    virtual double calculate() {
        return leftExp->calculate() - rightExp->calculate();
    }
};


#endif //PROJ1_MINUS_H
