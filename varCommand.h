//
// Created by fatuity on 12/19/18.
//

#ifndef PROJ1_VARCOMMAND_H
#define PROJ1_VARCOMMAND_H

#include <string>
#include <map>
#include "Value.h"

using namespace std;

class varCommand {
    map<string, Value> symbolMap;
    Expressioner *expressioner;
public:
    varCommand(Expressioner *expr) {
        expressioner = expr;
    }

    double execute();

    bool isLegitVar(string var);
};


#endif //PROJ1_VARCOMMAND_H
