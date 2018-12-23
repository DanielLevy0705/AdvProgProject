//
// Created by elronbandel on 12/23/18.
//

#ifndef COMMANDSET_H
#define COMMANDSET_H

#include <list>
#include "Expression.h"
#include "Expressioner.h"

class CommandSet : public Expression {
    Expressioner* expressioner;
    list<list<Expression*>> set;

    CommandSet(Expressioner* exprer) {
        expressioner = exprer;
    }

    void pushLine(list<Expression*> line) {
        set.push_back(line);
    }

public:
    string getString() const override {
        return std::__cxx11::string();
    }

    double calculate() const override {
        for(auto& line : set) {
            expressioner->push(line);
        }
    }


};

#endif //UNTITLED4_COMMANDSET_H
