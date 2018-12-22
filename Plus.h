#ifndef PROJ1_PLUS_H
#define PROJ1_PLUS_H


#include "Expression.h"

class Plus : public Expression {
    Expression *leftExp, *rightExp;
    string strRep;
public:
    Plus(string strVal, Expression *left, Expression *right) {
        leftExp = left;
        rightExp = right;
        strVal = strRep;
    }

    virtual double calculate() {
        return leftExp->calculate() + rightExp->calculate();
    }

    virtual string getString() {
        return strRep;
    }
};


#endif //PROJ1_PLUS_H