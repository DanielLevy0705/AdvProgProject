#ifndef STRINGEXPRESSION_H
#define STRINGEXPRESSION_H

#include <string>
#include "Expression.h"

using namespace std;

class StringExpression : public Expression {
    string str;

public:
    explicit StringExpression(const string &stri) {
        str = stri;
    }

    double calculate() const override {
        return 1;
    }

    string getString() const override {
        return str;
    }
    const type_info& getType() const override {
        return typeid(StringExpression);
    }
};

#endif //UNTITLED4_STRINGEXPRESSION_H
