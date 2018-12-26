#ifndef PROJ1_PLUS_H
#define PROJ1_PLUS_H


#include "Expointer.h"
#include "MathExpression.h"

class Plus : public MathExpression {
    Expointer leftExp, rightExp;
public:
    Plus( Expointer left, Expointer right) {
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