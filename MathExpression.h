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

    string getString() const override {
        double res = this->calculate();
        if ((int)res == res)
            return to_string((int)res);
        return to_string(res);
    }
};


#endif //UNTITLED4_MATHEXPRESSION_H
