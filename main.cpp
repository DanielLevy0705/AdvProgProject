
#include "Expressioner.h"
#include "BindedSymbolMap.h"
#include "OpenDataServerCommand.h"
#include "ConnectCommand.h"
#include <map>
using namespace std;

int main() {
    BindedSymbolMap* symap = new BindedSymbolMap; //will be connected to data server and flight server
    Expressioner* expressioner = new Expressioner(symap);
    map<string, Expression*> commandsDictionary = {{"openDataServer",new OpenDataServerCommand(symap, expressioner)},
                                                  {"connect",new ConnectCommand(symap, expressioner)}};

    expressioner->initiate(commandsDictionary);

    
    while (expressioner->on()) {
        expressioner->popNext()->calculate();
    }
    delete symap;
    delete expressioner;
}