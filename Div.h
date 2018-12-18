#ifndef PROJ1_DIV_H
#define PROJ1_DIV_H


#include "Expression.h"

class Div : public Expression {
    Expression *leftExp;
    Expression *rightExp;
public:
    Div(Expression *left, Expression *right) {
        leftExp = left;
        rightExp = right;
    }

    virtual double calculate() {
        return this->leftExp->calculate() / this->rightExp->calculate();
    }
};


#endif //PROJ1_DIV_H
