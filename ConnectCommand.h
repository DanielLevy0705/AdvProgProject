//
// Created by elronbandel on 12/22/18.
//

#ifndef CONNECTCOMMAND_H
#define CONNECTCOMMAND_H


#include "BindedSymbolMap.h"
#include "Expressioner.h"

class ConnectCommand : public Expression {

    Expressioner *expressioner;
    BindedSymbolMap *symap;

public:
    //constructor:
    ConnectCommand(BindedSymbolMap *bindedSymbolMap, Expressioner *expr) {
        symap = bindedSymbolMap;
        expressioner = expr;
    }

    double calculate() const override {

        if (expressioner->argumentsInLine() != 2)
            throw string("Error: not enough argument for:" + getString());

        try {

            string ip = expressioner->popNext()->getString();
            int port = (int) expressioner->popNext()->calculate();

            symap->connect(ip, port);

        } catch (const string &err) {
            throw string("Error: failed Connecting because:" + err);
        }


    }

    string getString() const override {
        return "ConnectCommand";
    }

    virtual void print(ostream &out) const {
        out << "ConnectCommand";
    }
};


#endif //UNTITLED4_CONNECTCOMMAND_H
