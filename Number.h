//
// Created by fatuity on 12/18/18.
//

#ifndef PROJ1_NUMBER_H
#define PROJ1_NUMBER_H


#include <string>
#include "Expression.h"
#include "MathExpression.h"

class Number : public MathExpression {
    string number;
public:
    Number(std::string num) {
        number = num;
    }

    virtual double calculate() const {
        return stod(number);
    }

    virtual string getString() const {
        return number;
    }
    const type_info& getType() const override {
        return typeid(Number);
    }
};


#endif //PROJ1_NUMBER_H
