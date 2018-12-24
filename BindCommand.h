//
// Created by elronbandel on 12/23/18.
//

#ifndef BINDCOMMAND_H
#define BINDCOMMAND_H


#include "Expression.h"
#include "Expressioner.h"

class BindCommand: public Expression {

    BindedSymbolMap* symap;
    Expressioner *expressioner;

public:
    //constructor:
    explicit BindCommand(Expressioner *expr, BindedSymbolMap* symbolMap) {
        expressioner = expr;
        symap = symbolMap;
    }

    double calculate() const override {
        throw string("Error: 'bind' can be used only after '='.");
    }

    string getString() const override {
        if (symap->canBind()) {
            if (expressioner->argumentsInLine() != 1)
                throw string("Error: 'bind' should get only one argument.");
            if (typeid(*expressioner->next()) != typeid(StringExpression))
                throw string("Error: 'bind' should get string: \"...\"");
            string path = expressioner->popNext()->getString();
            if(!symap->exist(path))
                throw string("Error: \"" + path + "\" not generic, cannot be binded.");
            return expressioner->popNext()->getString();
        } else
            throw string("Error: can 'bind' only after 'connect'.");

    }

    virtual void print(ostream &out) const {
        out << "ConnectCommand";
    }
};


#endif //BINDCOMMAND_H
