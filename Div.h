#ifndef PROJ1_DIV_H
#define PROJ1_DIV_H


#include "Expointer.h"
#include "MathExpression.h"

class Div : public MathExpression {
    Expointer  leftExp;
    Expointer  rightExp;
public:
    Div( Expointer  left, Expointer  right) {
        if (right->calculate() == 0) {
            throw "dividing by zero exception";
        }
        leftExp = left;
        rightExp = right;
    }

    virtual double calculate() const {
        return this->leftExp->calculate() / this->rightExp->calculate();
    }

    const type_info& getType() const override {
        return typeid(Div);
    }
};


#endif //PROJ1_DIV_H
