#ifndef PROJ1_EXPRESSION_H
#define PROJ1_EXPRESSION_H


#include <string>

using namespace std;

class Expression {
public:
    virtual double calculate() = 0;

    virtual string getString() = 0;
};


#endif //PROJ1_EXPRESSION_H