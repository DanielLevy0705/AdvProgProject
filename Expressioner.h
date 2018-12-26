

#include <string>

#include "Command.h"
#include "BindedSymbolMap.h"


#ifndef EXPRESSIONER_H
#define EXPRESSIONER_H

#include "CommandSet.h"

class Parser;

using namespace std;

class Expressioner {
    Parser *parser;
    list<list<Expression *>> reserve;
    list<Expression *> expressions;
    bool active;

public:

    explicit Expressioner(BindedSymbolMap *symap);

    void initiate(map<string, Command *> dictionary);

    Expression *popNext();

    Expression *next();

    void push(list<Expression *> expList);

    bool on() { return active; }

    int argumentsInLine() { return (int) expressions.size(); }

    void close() {
        active = false;
    }

    ~Expressioner();

private:
    //if there is no more expressions get more from parser or from reserve
    void load();

};


#endif //EXPRESSIONER_H
