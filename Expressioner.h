//
// Created by elronbandel on 12/19/18.
//
#include <list>
#include "Parser.h"
#include "Expression.h"

#ifndef EXPRESSIONER_H
#define EXPRESSIONER_H
using namespace std;
class Expressioner {
    Parser parser;
    list<list<Expression&>> reserve;
    list<Expression &> expressions;

public:
    Expressioner() : parser() {}

    void initiate(Parser& prsr) {
        parser parser;
    }

    Expression &popNext() {
        if (expressions.empty()) {
            load();
        }
        return expressions.pop_back();
    }

    Expression next() {
        if (expressions.empty())
            return NULL;
        return expressions.back();
    }

    void push(list<Expression&> expList) {
        reserve.emplace_front(expression);
    }

private:
    void load() {
        //if there is no more expressions get more from parser or from reserve
        if (reserve.empty()) {
            expressions = parser.next();
        } else {
            expressions = reserve.pop_back();
        }
    }

}

#endif //EXPRESSIONER_H
