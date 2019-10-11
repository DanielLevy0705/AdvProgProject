//
// Created by elronbandel on 12/24/18.
//

#ifndef OPENSETEXPRESSION_H
#define OPENSETEXPRESSION_H

#include "Command.h"


class StartSetExpression : public Command {

public:
    string getString() const override {
        return "{";
    }

    double execute() const override {
        return 0;
    }
};

class EndSetExpression : public Command {
public:
    string getString() const override {
        return "}";
    }


    double execute() const override {
        return 0;
    }

};


#endif //OPENSETEXPRESSION_H
