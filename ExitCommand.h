//
// Created by fatuity on 12/25/18.
//

#ifndef UNTITLED4_EXITCOMMAND_H
#define UNTITLED4_EXITCOMMAND_H


#include "Expression.h"
#include "Expressioner.h"

class ExitCommand : public Expression {
    Expressioner *expressioner;
public:
    explicit ExitCommand(Expressioner *expnr) {
        expressioner = expnr;
    }

    virtual string getString() const {
        return "ExitCommand";
    }

    virtual void print(ostream &out) const {
        out << "ExitCommand";
    }

    virtual double calculate() const {
        expressioner->close();
    }
};


#endif //UNTITLED4_EXITCOMMAND_H
