//
// Created by fatuity on 12/19/18.
//

#include "varCommand.h"
#include "Expression.h"

double varCommand::execute(){
    Expression variable = expressioner->popNext();
    if (!isLegitVar(variable.getString())){
        throw variable + " is not a legitimate variable";
    }
    Expression assignment = expressioner->popNext();
    if (assignment.getString()!= "="){
        throw "no assignment operator in var declaration";
    }
    Value val = assignment.caclculate();
    symbolMap.insert(pair<string,Value>(variable.getString(),val));
}
bool varCommand::isLegitVar(string var) {
    for (int i=0; i<var.size(); i++){
        if(!isdigit(var[i]) || !isalpha(var[i]) || var[i]!= '_'){
            return false;
        }
    }
    return true;
}
