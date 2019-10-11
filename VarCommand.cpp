//
// Created by elronbandel on 12/25/18.
//
#include "VarCommand.h"

double VarCommand::execute() const  {
    if (expressioner->argumentsInLine() >= 1 &&
        expressioner->next()->getType() == typeid(NewExpression)) {
        string name = expressioner->popNext()->getString();
        symap->set(name, new LocalValue(0));
        ValueExpression(symap, expressioner, name).calculate();
    } else {
        throw string("Error: no compitable arguments after 'var'");
    }
    return 0;
}