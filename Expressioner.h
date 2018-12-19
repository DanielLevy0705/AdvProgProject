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
    list<Expression &> expressions;

public:
    Expressioner(Parser prsr) : parser(prsr) {}

    Expression &popNext() {
        return expressions.pop_back();
    }

    Expression next() {
        return expressions.back();
    }

    void push(Expression &expression) {
        expressions.emplace(expression);
    }

private:
    void load() {
        //if there is no more expressions get more from parser
        if (expressions.empty()) {
            expressions = parser.next();
        }
    }

}

#endif //EXPRESSIONER_H
