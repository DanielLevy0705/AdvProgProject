

#include "Inputer.h"
#include "Expressioner.h"

int main() {
    BindedSymbolMap* symap = new BindedSymbolMap; //will be connected to data server and flight server
    Expressioner* expressioner = new Expressioner(map<string, Expression> =
                                                  new {"var",VarCommand(&expressioner, symap)},
                                                  new {"openDataServer",DataServerOpenCommand(&expressioner, dataServer)},
                                                  new {"connect",ConnectCommend(&expressioner, table)});

    while (expressioner.on()) {
        expressioner.popNext().calculate();
    }
    delete symap;
}