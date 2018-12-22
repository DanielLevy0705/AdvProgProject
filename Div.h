#ifndef PROJ1_DIV_H
#define PROJ1_DIV_H


#include <string>
#include "Expression.h"

class Div : public Expression {
    Expression *leftExp;
    Expression *rightExp;
    string strRep;
public:
    Div(string strVal, Expression *left, Expression *right) {
        if (right->calculate() == 0) {
            throw "dividing by zero exception";
        }
        leftExp = left;
        rightExp = right;
        strRep = strVal;
    }

    virtual double calculate() {
        return this->leftExp->calculate() / this->rightExp->calculate();
    }

    virtual string getString() {
        return strRep;
    }
};


#endif //PROJ1_DIV_H
