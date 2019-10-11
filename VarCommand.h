//
// Created by elronbandel on 12/23/18.
//


#ifndef VARCOMMAND_H


#include "BindedSymbolMap.h"
#include "ValueExpression.h"
#include "NewExpression.h"
#include "Command.h"

class Expressioner;


class VarCommand : public Command {

    Expressioner *expressioner;
    BindedSymbolMap *symap;

public:
    //constructor:
    VarCommand(BindedSymbolMap *bindedSymbolMap, Expressioner *expr) {
        symap = bindedSymbolMap;
        expressioner = expr;
    }

    double execute() const override;

    string getString() const override {
        return "ConnectCommand";
    }

};

#define VARCOMMAND_H

#endif //UNTITLED4_VARCOMMAND_H
