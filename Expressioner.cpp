#include "Expressioner.h"
#include "Parser.h"

Expressioner::Expressioner(BindedSymbolMap *symap) {
    active = true;
    parser = new Parser(symap, this);
}

void Expressioner::initiate(map<string, Command *> dictionary, const string& path) {
    parser->initiate(dictionary, path);
}

Expointer Expressioner::popNext() {
    if (expressions.empty()) {
        load();
    }
    Expointer next = expressions.front();
    //pop only if next!= null
    if (next != nullptr) {
        expressions.pop_front();
    }
    return next;
}

Expointer Expressioner::next() {
    if (expressions.empty())
        return nullptr;
    return expressions.front();
}

void Expressioner::push(list<Expointer> expList) {
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