#ifndef BINDCOMMAND_H
#define BINDCOMMAND_H

#include "Expressioner.h"
#include "Command.h"
#include "StringExpression.h"

class BindCommand : public Command {

    BindedSymbolMap *symap;
    Expressioner *expressioner;

public:
    //constructor:
    explicit BindCommand(Expressioner *expr, BindedSymbolMap *symbolMap) {
        expressioner = expr;
        symap = symbolMap;
    }

    double execute() const override {
        throw string("Error: 'bind' can be used only after '='.");
    }

    string getString() const override {
        if (symap->canBind()) {
            if (expressioner->argumentsInLine() != 1)
                throw string("Error: 'bind' should get only one argument.");
            if (expressioner->next()->getType() != typeid(StringExpression))
                throw string("Error: 'bind' should get string: \"...\"");
            string path = expressioner->popNext()->getString();
            if (!symap->exist(path))
                throw string("Error: \"" + path + "\" not generic, cannot be binded.");
            return path;
        } else
            throw string("Error: can 'bind' only after 'connect'.");

    }
};


#endif //BINDCOMMAND_H
