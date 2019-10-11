#include "BindCommand.h"
#include "ValueExpression.h"

string BindCommand::getString() const  {
    if (true) {
        if (expressioner->argumentsInLine() != 1)
            throw string("Error: 'bind' should get only one argument.");
        if (expressioner->next()->getType() != typeid(StringExpression)
            && expressioner->next()-> getType() != typeid(ValueExpression))
            throw string("Error: 'bind' should get string: \"...\" or variable");
        string path;
        if (expressioner->next()->getType() == typeid(ValueExpression)) {
            path =((ValueExpression*)(expressioner->popNext().get()))->getName();
        } else {
            path = expressioner->popNext()->getString();
        }
        if (!symap->exist(path)) {
            symap->set(path, new LocalValue(0));
        }
        return path;
    } else
        throw string("Error: can 'bind' only after 'connect'.");

}
