#ifndef PROJ1_MINUS_H
#define PROJ1_MINUS_H


#include "Expointer.h"
#include "MathExpression.h"

class Minus : public MathExpression {
    Expointer leftExp, rightExp;
public:
    Minus( Expointer left, Expointer right) {
        leftExp = left;
        rightExp = right;
    }

    virtual double calculate() const {
        return leftExp->calculate() - rightExp->calculate();
    }
    const type_info& getType() const override {
        return typeid(Minus);
    }
};


#endif //PROJ1_MINUS_H
