//
// Created by elronbandel on 12/19/18.
//

#ifndef DATASERVEROPENCOMMAND_H
#define DATASERVEROPENCOMMAND_H

#include "Expressioner.h"

class OpenDataServerCommand {
    Expressioner* expressioner;
    
    calculate() {
        Expression& prt = expressioner->next();
        Expression& frq = expressioner->next();
        
        try {
            openDataServer((int)prt.calculate(), (int)frq.calculate())
        }
        
    }
    
    
    void openDataServer(int port, int frequency) {
        
    }
};

#endif //DATASERVEROPENCOMMAND_H
