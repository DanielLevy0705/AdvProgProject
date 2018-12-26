#include "ConditionExpression.h"
#include "Expointer.h"
double ConditionExpression::calculate() const {
    //switch the condition cases by the strVal and check if the condition is true
    switch (conditionMap.at(strVal)) {
        case Less:
            if (leftExp->calculate() < rightExp->calculate()) {
                return 1;
            }
            return 0;
        case Bigger:
            if (leftExp->calculate() > rightExp->calculate()) {
                return 1;
            }
            return 0;
        case LessEqual:
            if (leftExp->calculate() <= rightExp->calculate()) {
                return 1;
            }
            return 0;
        case BiggerEqual:
            if (leftExp->calculate() >= rightExp->calculate()) {
                return 1;
            }
            return 0;
        case Equal:
            if (leftExp->calculate() == rightExp->calculate()) {
                return 1;
            }
            return 0;
        case NotEqual:
            if (leftExp->calculate() != rightExp->calculate()) {
                return 1;
            }
            return 0;
    }
}