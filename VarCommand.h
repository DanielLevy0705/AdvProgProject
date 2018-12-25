//
// Created by elronbandel on 12/23/18.
//


#ifndef VARCOMMAND_H

#include "Expressions.h"
#include "BindedSymbolMap.h"
#include "ValueExpression.h"
#include "NewExpression.h"

class Expressioner;


class VarCommand: public Expression {

    Expressioner *expressioner;
    BindedSymbolMap *symap;

public:
    //constructor:
    VarCommand(BindedSymbolMap *bindedSymbolMap, Expressioner *expr) {
        symap = bindedSymbolMap;
        expressioner = expr;
    }

    double calculate() const override;

    string getString() const override {
        return "ConnectCommand";
    }

    virtual void print(ostream &out) const {
        out << "ConnectCommand";
    }

};

#define VARCOMMAND_H

#endif //UNTITLED4_VARCOMMAND_H
