#ifndef PROJ1_MULT_H
#define PROJ1_MULT_H


#include "Expression.h"
#include "MathExpression.h"

class Mult : public MathExpression {
    Expression *leftExp, *rightExp;
public:
    Mult(Expression *left, Expression *right) {
        leftExp = left;
        rightExp = right;
    }

    virtual double calculate() const {
        return leftExp->calculate() * rightExp->calculate();
    }

    const type_info& getType() const override {
        return typeid(Mult);
    }
};


#endif //PROJ1_MULT_H
