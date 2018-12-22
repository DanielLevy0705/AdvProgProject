//
// Created by elronbandel on 12/21/18.
//

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
using namespace std;
class Expression {
protected:

public:

    virtual double calculate() = 0;
    virtual operator string() = 0;
};


#endif //EXPRESSION_H
