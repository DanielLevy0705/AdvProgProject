//
// Created by elronbandel on 12/25/18.
//

#include "CommandSet.h"

double CommandSet::calculate() const  {
    for(auto& line : set) {
        expressioner->push(line);
    }
}

