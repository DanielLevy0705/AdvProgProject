//
// Created by fatuity on 12/19/18.
//

#include "varCommand.h"
#include "Expression.h"

double varCommand::execute() {
    Value val;
    Expression variable = expressioner->next();
    if (!isLegitVar(variable.getString())) {
        throw variable + " is not a legitimate variable";
    }
    variable = expressioner->popNext();
    Expression assignment = expressioner->next();
    if ((assignment.getString() != "=") && (assignment != nullptr) {
        throw "no assignment operator in var declaration";
    }
    if (assignment != nullptr) {
        val = assignment.caclculate();
    } else {
        val = 0;
    }
    symbolMap.insert(pair<string, Value>(variable.getString(), val));
}

bool varCommand::isLegitVar(string var) {
    for (int i = 0; i < var.size(); i++) {
        if (isdigit(var[0])) {
            return false;
        }
        if (!isdigit(var[i]) && !isalpha(var[i]) && var[i] != '_') {
            return false;
        }
    }
    return true;
}
