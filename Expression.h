#ifndef PROJ1_EXPRESSION_H
#define PROJ1_EXPRESSION_H


#include <string>
#include <iostream>

using namespace std;

class Expression {
    virtual void print(ostream &out) const = 0;

public:

    virtual double calculate() const = 0;

    virtual string getString() const = 0;

    friend ostream &operator<<(ostream &out, const Expression &e) {
        e.print(out);
        return out;
    }
};


#endif //PROJ1_EXPRESSION_H