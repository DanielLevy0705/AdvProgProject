#ifndef PROJ1_MINUS_H
#define PROJ1_MINUS_H


#include "Expression.h"
#include "MathExpression.h"

class Minus : public MathExpression {
    Expression *leftExp, *rightExp;
    string strRep;
public:
    Minus(string strVal, Expression *left, Expression *right) {
        leftExp = left;
        rightExp = right;
        strRep = strVal;
    }

    virtual double calculate() const {
        return leftExp->calculate() - rightExp->calculate();
    }

    virtual string getString() const {
        return strRep;
    }
};


#endif //PROJ1_MINUS_H
