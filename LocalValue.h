#include "Value.h"
#ifndef LOCALVALUE_H
#define LOCALVALUE_H

using namespace std;

class LocalValue: public Value {
    double value;
public:
    explicit LocalValue(double val) {
        value = val;
    }
    void operator = (double num) {
        value = num;
    }
    operator double() {
        return value;
    }

    operator string() {
        if ((int) value == value)
            return to_string((int)value);
        return to_string(value);
    }
};

class StringValue: public Value {
    string value;
public:
    explicit StringValue(const string& val) {
        value = val;
    }
    void operator = (double num) {
        value = to_string(num);
    }
    operator double() {
        return -1;
    }
    operator string() {
        return value;
    }
};

#endif //LOCALVALUE_H
