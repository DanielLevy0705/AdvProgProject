#ifndef PROJ1_MULT_H
#define PROJ1_MULT_H


#include "Expointer.h"
#include "MathExpression.h"

class Mult : public MathExpression {
    Expointer leftExp, rightExp;
public:
    Mult(Expointer left, Expointer right) {
        leftExp = left;
        rightExp = right;
    }

    virtual double calculate() const {
        return leftExp->calculate() * rightExp->calculate();
    }

    const type_info &getType() const override {
        return typeid(Mult);
    }
};


#endif //PROJ1_MULT_H
