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

    string getString() const override;
};


#endif //BINDCOMMAND_H
