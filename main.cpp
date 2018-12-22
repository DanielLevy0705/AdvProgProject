
#include "Expressioner.h"
#include "BindedSymbolMap.h"
#include "OpenDataServerCommand.h"
#include "ConnectCommand.h"

int main() {
    BindedSymbolMap* symap = new BindedSymbolMap; //will be connected to data server and flight server
    Expressioner* expressioner = new Expressioner(map<string, Expression*> =
                                              //    new {"var",VarCommand(expressioner, symap)},
                                                   {"openDataServer",new OpenDataServerCommand(symap, expressioner)},
                                                   {"connect",new ConnectCommand(symap, expressioner)});

    while (expressioner->on()) {
        expressioner->popNext()->calculate();
    }
    delete symap;
    delete expressioner;
}