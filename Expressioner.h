

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
    Expressioner(map<string, Expression*> expressions, BindedSymbolMap* symap) : parser(expressions, symap) {
        active = true;
    }

    void initiate(Parser& prsr) {
        parser = prsr;
    }

    Expression* popNext() {
        if (expressions.empty()) {
            load();
        }
        Expression* next = expressions.back();
        expressions.pop_back();
        return next;
    }

    Expression* next() {
        if (expressions.empty())
            return nullptr;
        return expressions.back();
    }

    void push(list<Expression*> expList) {
        reserve.emplace_front(expList);
    }

    bool on() {
        return active;
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
