//
// Created by elronbandel on 12/20/18.
//
#include "Value.h"
#ifndef LOCALVALUE_H
#define LOCALVALUE_H

class LocalValue: public Value {
    double value;
public:
    LocalValue(double val) {
        value = val;
    }
    void operator = (double num) {
        value = num;
    }
    operator double() {
        return value;
    }
};

#endif //LOCALVALUE_H
