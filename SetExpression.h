//
// Created by elronbandel on 12/24/18.
//

#ifndef OPENSETEXPRESSION_H
#define OPENSETEXPRESSION_H

#include "Expression.h"


class StartSetExpression : public Expression {

public:
    string getString() const override {
        return "{";
    }

    double calculate() const override {
        return 0;
    }
};

class EndSetExpression : public Expression {
public:
    string getString() const override {
        return "}";
    }


    double calculate() const override {
        return 0;
    }

};


#endif //OPENSETEXPRESSION_H
