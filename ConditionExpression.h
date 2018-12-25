//
// Created by fatuity on 12/23/18.
//

#ifndef UNTITLED4_CONDITIONEXPRESSION_H
#define UNTITLED4_CONDITIONEXPRESSION_H


#include <map>
#include "Expression.h"

class ConditionExpression : public Expression {
    Expression *leftExp, *rightExp;
    string strVal;
    enum Condition {
        Less, Bigger, LessEqual, BiggerEqual, Equal, NotEqual
    };
    map<string, Condition> conditionMap = {{"<",  Less},
                                           {">",  Bigger},
                                           {"<=", LessEqual},
                                           {">=", BiggerEqual},
                                           {"==", Equal},
                                           {"!=", NotEqual}};
public:
    ConditionExpression(string str, Expression *left, Expression *right) {
        strVal = str;
        leftExp = left;
        rightExp = right;
    }

    virtual double calculate() const {
        switch (conditionMap.at(strVal)) {
            case Less:
                if (leftExp->calculate() < rightExp->calculate()){
                    return 1;
                }
                return 0;
            case Bigger:
                if (leftExp->calculate() > rightExp->calculate()){
                    return 1;
                }
                return 0;
            case LessEqual:
                if (leftExp->calculate() <= rightExp->calculate()){
                    return 1;
                }
                return 0;
            case BiggerEqual:
                if (leftExp->calculate() >= rightExp->calculate()){
                    return 1;
                }
                return 0;
            case Equal:
                if (leftExp->calculate() == rightExp->calculate()){
                    return 1;
                }
                return 0;
            case NotEqual:
                if (leftExp->calculate() != rightExp->calculate()){
                    return 1;
                }
                return 0;
        }
    }

    virtual string getString() const {
        if (calculate() != 0) {
            return "true";
        } else {
            return "false";
        }
    }

    virtual void print(ostream &out) const {
        if (calculate() != 0) {
            out << "true";
        } else {
            out << "false";
        }
    }
};


#endif //UNTITLED4_CONDITIONEXPRESSION_H
