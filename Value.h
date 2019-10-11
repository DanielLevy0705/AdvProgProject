#ifndef VALUE_H
#define VALUE_H

#include <string>
#include "Expression.h"

using namespace std;

class Value {
public:
    virtual void operator=(double num) = 0;

    virtual operator double() = 0;

    virtual operator string() = 0;

    virtual ~Value() {}
};

#endif// VALUE_H
