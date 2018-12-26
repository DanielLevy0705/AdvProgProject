#ifndef UNTITLED4_CONDITIONEXPRESSION_H
#define UNTITLED4_CONDITIONEXPRESSION_H


#include <map>
#include "Expointer .h"

class ConditionExpression : public Expression {
    Expointer leftExp, rightExp;
    string strVal;
    enum Condition {
        Less, Bigger, LessEqual, BiggerEqual, Equal, NotEqual
    };
    map <string, Condition> conditionMap = {{"<",  Less},
                                            {">",  Bigger},
                                            {"<=", LessEqual},
                                            {">=", BiggerEqual},
                                            {"==", Equal},
                                            {"!=", NotEqual}};
public:
    ConditionExpression(string str, Expointer left, Expointer right) {
        strVal = str;
        leftExp = left;
        rightExp = right;
    }

    virtual double calculate() const;

    virtual string getString() const {
        if (calculate() != 0) {
            return "true";
        } else {
            return "false";
        }
    }

    const type_info &getType() const override {
        return typeid(ConditionExpression);
    }
};


#endif //UNTITLED4_CONDITIONEXPRESSION_H
