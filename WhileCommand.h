//
// Created by elronbandel on 12/25/18.
//

#ifndef WHILECOMMAND_H
#define WHILECOMMAND_H

#include "Command.h"
#include "Expressioner.h"
#include "CommandSet.h"
#include "ConditionExpression.h"
#include "SetExpression.h"

class WhileCommand: public Command {
    Expressioner* expressioner;

public:

    WhileCommand(Expressioner* exprer) {
        expressioner = exprer;
    }

    double execute()  const override {
        if ((expressioner->next()->getType()) == typeid(ConditionExpression)) {
            Expression* conditionExp = expressioner->popNext();
            bool condition = conditionExp->calculate();
            Expression* commandsExp = expressioner->popNext();
            if (condition) {
                if (commandsExp->getType() == typeid(CommandSet)) {

                    commandsExp->calculate();
                    //build line that will help the expressioner to start the while again
                    list<Expression*> whileLine;
                    whileLine.emplace_front(commandsExp);
                    whileLine.emplace_front(conditionExp);
                    whileLine.emplace_front((Expression*)this);
                    expressioner->push(whileLine);

                } else {
                    cout << "Error: no commands set inside { } after 'while'." <<endl;
                    // if it is other kind of command run like there was no while before
                    commandsExp->calculate();
                }
            }else if (commandsExp->getType() != typeid(CommandSet)) {
                // if it is other kind of command run like there was no while before
                commandsExp->calculate();
            }
        }
    }

    string getString() const override {
        return "while";
    }
};

#endif //UNTITLED4_WHILECOMMAND_H
