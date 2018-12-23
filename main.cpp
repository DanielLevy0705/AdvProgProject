
#include "Expressioner.h"
#include "BindedSymbolMap.h"
#include "OpenDataServerCommand.h"
#include "ConnectCommand.h"
#include "PrintCommand.h"
#include <map>
using namespace std;

int main() {
    BindedSymbolMap* symap = new BindedSymbolMap; //will be connected to data server and flight server
    Expressioner* expressioner = new Expressioner(symap);
    map<string, Expression*> commandsDictionary = {{"openDataServer",new OpenDataServerCommand(symap, expressioner)},
                                                  {"connect",new ConnectCommand(symap, expressioner)},
                                                  {"print", new PrintCommand(expressioner)}};

    expressioner->initiate(commandsDictionary);


    while (expressioner->on()) {
        try {

            Expression* exp = expressioner->popNext();
            exp->calculate();

        } catch (const string& errMsg) {
            cout << errMsg <<endl;
        }
    }
    delete symap;
    delete expressioner;
}