#ifndef PROJ1_PLUS_H
#define PROJ1_PLUS_H


#include "Expression.h"
#include "MathExpression.h"

class Plus : public MathExpression {
    Expression *leftExp, *rightExp;
public:
    Plus( Expression *left, Expression *right) {
        leftExp = left;
        rightExp = right;
    }

    virtual double calculate() const {
        return leftExp->calculate() + rightExp->calculate();
    }

    const type_info& getType() const override {
        return typeid(Plus);
    }
};


#endif //PROJ1_PLUS_H