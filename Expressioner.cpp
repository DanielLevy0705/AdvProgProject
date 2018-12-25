//
// Created by elronbandel on 12/23/18.
//
#include "Expressioner.h"
#include "Parser.h"

Expressioner::Expressioner(BindedSymbolMap *symap) {
    active = true;
    parser = new Parser(symap, this);
}

CommandSet *Expressioner::getCommandSet() {
    return parser->getCommandSet();
}

void Expressioner::initiate(map<string, Expression *> dictionary) {
    parser->initiate(dictionary);
}

Expression *Expressioner::popNext() {
    if (expressions.empty()) {
        load();
    }
    Expression *next = expressions.front();
    //pop only if next!= null
    if (next != nullptr) {
        expressions.pop_front();
    }
    return next;
}

Expression *Expressioner::next() {
    if (expressions.empty())
        return nullptr;
    return expressions.front();
}

void Expressioner::push(list<Expression *> expList) {
    reserve.emplace_front(expList);
}

void Expressioner::load() {
    //if there is no more expressions get more from parser or from reserve
    if (reserve.empty()) {
        expressions = parser->next();
    } else {
        expressions = reserve.back();
        reserve.pop_back();
    }
}

Expressioner::~Expressioner() {
    delete parser;
}