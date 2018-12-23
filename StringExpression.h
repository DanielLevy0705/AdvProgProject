//
// Created by elronbandel on 12/23/18.
//

#ifndef STRINGEXPRESSION_H
#define STRINGEXPRESSION_H

#include <string>
#include "Expression.h"

using namespace std;

class StringExpression: public Expression{
    string str;

public:
    explicit StringExpression(const string& stri) {
        str = stri;
    }

    double calculate() override {
        return 1;
    }

    string getString() override{
        return str;
    }
};

#endif //UNTITLED4_STRINGEXPRESSION_H
