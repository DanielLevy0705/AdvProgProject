//
// Created by elronbandel on 12/23/18.
//


#ifndef VARCOMMAND_H


#include "Expression.h"
#include "BindedSymbolMap.h"
#include "Expressioner.h"
#include "NewExpression.h"
#include "ValueExpression.h"

class VarCommand: public Expression {

    Expressioner *expressioner;
    BindedSymbolMap *symap;

public:
    //constructor:
    VarCommand(BindedSymbolMap *bindedSymbolMap, Expressioner *expr) {
        symap = bindedSymbolMap;
        expressioner = expr;
    }

    double calculate() const override {
        if (expressioner->argumentsInLine() >= 1 &&
                typeid((*(expressioner->next()))) == typeid(NewExpression)) {
            string name = expressioner->popNext()->getString();
            symap->set(name, new LocalValue(0));
            ValueExpression(symap, expressioner, name).calculate();
        } else {
            throw string("Error: no compitable arguments after 'var");
        }
    }

    string getString() const override {
        return "ConnectCommand";
    }

    virtual void print(ostream &out) const {
        out << "ConnectCommand";
    }

};

#define VARCOMMAND_H

#endif //UNTITLED4_VARCOMMAND_H
