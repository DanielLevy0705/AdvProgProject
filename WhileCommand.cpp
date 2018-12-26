//
// Created by elronbandel on 12/26/18.
//
#include "WhileCommand.h"
#include "Expointer.h"
#include "CommandExpression.h"

double WhileCommand::execute() const  {
    if ((expressioner->next()->getType()) == typeid(ConditionExpression)) {
        Expointer conditionExp = expressioner->popNext();
        bool condition = conditionExp->calculate();
        Expointer commandsExp = expressioner->popNext();
        if (condition) {
            if (commandsExp->getType() == typeid(CommandSet)) {

                commandsExp->calculate();
                //build line that will help the expressioner to start the while again
                list<Expointer> whileLine;
                whileLine.emplace_front(commandsExp);
                whileLine.emplace_front(conditionExp);
                whileLine.emplace_front(newExpointer(new CommandExpression(new WhileCommand(expressioner))));
                expressioner->push(whileLine);

            } else {
                cout << "Error: no commands set inside { } after 'while'." << endl;
                // if it is other kind of command run like there was no while before
                commandsExp->calculate();
            }
        } else if (commandsExp->getType() != typeid(CommandSet)) {
            // if it is other kind of command run like there was no while before
            commandsExp->calculate();
        }
    }
    return 0;
}
