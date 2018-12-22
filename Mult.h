//
// Created by fatuity on 12/18/18.
//

#ifndef PROJ1_MULT_H
#define PROJ1_MULT_H


#include "Expression.h"

class Mult : public Expression {
    Expression *leftExp, *rightExp;
    string strRep;
public:
    Mult(string strVal,Expression *left, Expression *right) {
        leftExp = left;
        rightExp = right;
        strRep = strVal;
    }

    virtual double calculate() {
        return leftExp->calculate() * rightExp->calculate();
    }

    virtual string getString(){
        return strRep;
    }
};


#endif //PROJ1_MULT_H
