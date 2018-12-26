//
// Created by fatuity on 12/22/18.
//

#ifndef PROJ1_NEG_H
#define PROJ1_NEG_H


#include "Expression.h"
#include "MathExpression.h"

class Neg : public MathExpression {
    Expression* expression;
public:
    Neg( Expression* exp) {
        expression = exp;
    }

    virtual double calculate() const {
        return -expression->calculate();
    }

    const type_info& getType() const override {
        return typeid(Neg);
    }
};


#endif //PROJ1_NEG_H
