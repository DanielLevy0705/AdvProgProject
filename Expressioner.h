

#ifndef EXPRESSIONER_H
#define EXPRESSIONER_H

#include "Parser.h"
#include "Expression.h"
#include <list>
#include <string>

using namespace std;

class Expressioner {
    Parser parser;

    list<list<Expression*>> reserve;
    list<Expression*> expressions;
    bool active;

public:
    explicit Expressioner(BindedSymbolMap* symap) : parser(symap) {
        active = true;
    }

    void initiate(map<string, Expression*> dictionary) {
        parser.initiate(dictionary);
    }

    Expression* popNext() {
        if (expressions.empty()) {
            load();
        }
        Expression* next = expressions.front();
        expressions.pop_front();
        return next;
    }

    Expression* next() {
        if (expressions.empty())
            return nullptr;
        return expressions.front();
    }

    void push(list<Expression*> expList) {
        reserve.emplace_front(expList);
    }

    bool on() {
        return active;
    }

    int argumentsInLine() {
        return expressions.size();
    }

private:
    void load() {
        //if there is no more expressions get more from parser or from reserve
        if (reserve.empty()) {
            expressions = parser.next();
        } else {
            expressions = reserve.back();
            reserve.pop_back();
        }
    }



};


#endif //EXPRESSIONER_H
