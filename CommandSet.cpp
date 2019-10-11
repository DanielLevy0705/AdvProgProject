#include "Expressioner.h"
#include "CommandSet.h"

double CommandSet::calculate() const  {
    for(auto& line : set) {
        expressioner->push(line);
    }
}

