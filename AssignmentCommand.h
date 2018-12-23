//
// Created by elronbandel on 12/23/18.
//

#ifndef ASSIGNMENTCOMMAND_H
#define ASSIGNMENTCOMMAND_H

#include "Expressions.h"


class AssignmentCommand : public Expression {
public:
    AssignmentCommand(){}

    string getString() const override {
        throw string("Error: '=' can be put only after memory stored value");
    }

    double calculate() const override {
        throw string("Error: '=' can be put only after memory stored value");
    }
};

#endif //UNTITLED4_ASSIGNMENTCOMMAND_H
