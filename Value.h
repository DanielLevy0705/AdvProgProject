//
// Created by elronbandel on 12/20/18.
//

#ifndef VALUE_H
#define VALUE_H
class Value {
public:
    virtual void operator = (double num) = 0;
    virtual operator double() = 0;
};

#endif// VALUE_H
