//
// Created by elronbandel on 12/22/18.
//

#ifndef OPENDATASERVERCOMMAND_H
#define OPENDATASERVERCOMMAND_H

#include "Expressioner.h"
#include "BindedSymbolMap.h"

class OpenDataServerCommand : public Expression {
    BindedSymbolMap *symap;
    Expressioner *expressioner;
public:
    OpenDataServerCommand(BindedSymbolMap *bindedSymbolMap, Expressioner *expr) {
        symap = bindedSymbolMap;
        expressioner = expr;
    }

    double calculate() const override {
        if (expressioner->argumentsInLine() != 2)
            throw string("Error: not enough argument for:" + getString());
        try {
            int port = (int) expressioner->popNext()->calculate();
            int frequency = (int) expressioner->popNext()->calculate();
            symap->openDataServer(port, frequency);
        } catch (const string &err) {
            throw string("Error: failed opening data server because:" + err);
        }
    }

    virtual string getString() const {
        return string("openDataServerCommand");
    }

    virtual void print(ostream &out) const {
        out << "openDataServerCommand";
    }
};


#endif //OPENDATASERVERCOMMAND_H
