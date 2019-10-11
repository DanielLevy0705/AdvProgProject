#ifndef UNTITLED4_COMMANDEXPRESSION_H
#define UNTITLED4_COMMANDEXPRESSION_H


#include "Expression.h"
#include "Command.h"

class CommandExpression : public Expression {
    Command *command;
public:
    explicit CommandExpression(Command *c) {
        command = c;
    }

    string getString() const override {
        return command->getString();
    }

    double calculate() const override {
        return command->execute();
    }

    const type_info &getType() const override {
        return typeid(*command);
    }
};


#endif //UNTITLED4_COMMANDEXPRESSION_H
