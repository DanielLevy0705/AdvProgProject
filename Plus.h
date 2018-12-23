#ifndef PROJ1_PLUS_H
#define PROJ1_PLUS_H


#include "Expression.h"
#include "MathExpression.h"

class Plus : public MathExpression {
    Expression *leftExp, *rightExp;
    string strRep;
public:
    Plus(string strVal, Expression *left, Expression *right) {
        leftExp = left;
        rightExp = right;
        strVal = strRep;
    }

    virtual double calculate() const {
        return leftExp->calculate() + rightExp->calculate();
    }

    virtual string getString() const {
        return strRep;
    }
};


#endif //PROJ1_PLUS_H