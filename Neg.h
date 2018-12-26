#ifndef PROJ1_NEG_H
#define PROJ1_NEG_H


#include "Expointer.h"
#include "MathExpression.h"

class Neg : public MathExpression {
    Expointer expression;
public:
    Neg( Expointer  exp) {
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
