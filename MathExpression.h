//
// Created by fatuity on 12/23/18.
//

#ifndef UNTITLED4_MATHEXPRESSION_H
#define UNTITLED4_MATHEXPRESSION_H


#include "Expression.h"

class MathExpression : public Expression {
    virtual void print(ostream &out) const {
        out << calculate();
    }

public:
    virtual double calculate() const = 0;

    virtual string getString() const = 0;
};


#endif //UNTITLED4_MATHEXPRESSION_H
