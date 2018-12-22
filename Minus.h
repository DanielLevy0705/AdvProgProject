#ifndef PROJ1_MINUS_H
#define PROJ1_MINUS_H


#include "Expression.h"

class Minus : public Expression {
    Expression *leftExp, *rightExp;
    string strRep;
public:
    Minus(string strVal, Expression *left, Expression *right) {
        leftExp = left;
        rightExp = right;
        strRep = strVal;
    }

    virtual double calculate() {
        return leftExp->calculate() - rightExp->calculate();
    }

    virtual string getString(){
        return strRep;
    }
};


#endif //PROJ1_MINUS_H
