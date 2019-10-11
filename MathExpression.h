#ifndef UNTITLED4_MATHEXPRESSION_H
#define UNTITLED4_MATHEXPRESSION_H


#include "Expression.h"

//abstract class to represent any math expression
class MathExpression : public Expression {
public:
    virtual double calculate() const = 0;

    //return the value of the calculation of the expression as a string.
    string getString() const override {
        double res = this->calculate();
        if ((int) res == res)
            return to_string((int) res);
        return to_string(res);
    }

    const type_info &getType() const = 0;
};


#endif //UNTITLED4_MATHEXPRESSION_H
