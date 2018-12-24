
#include "ProgramTools.h"
#include "Commands.h"
#include "Expressions.h"
#include "SetExpression.h"
#include <map>
using namespace std;

int main() {
    vector<string> bindPaths = {"/instrumentation/airspeed-indicator/indicated-speed-kt",
                                "/instrumentation/altimeter/indicated-altitude-ft",
                                "/instrumentation/altimeter/pressure-alt-ft",
                                "/instrumentation/attitude-indicator/indicated-pitch-deg",
                                "/instrumentation/attitude-indicator/indicated-roll-deg",
                                "/instrumentation/attitude-indicator/internal-pitch-deg",
                                "/instrumentation/attitude-indicator/internal-roll-deg",
                                "/instrumentation/encoder/indicated-altitude-ft",
                                "/instrumentation/encoder/pressure-alt-ft",
                                "/instrumentation/gps/indicated-altitude-ft",
                                "/instrumentation/gps/indicated-ground-speed-kt",
                                "/instrumentation/gps/indicated-vertical-speed",
                                "/instrumentation/heading-indicator/indicated-heading-deg",
                                "/instrumentation/magnetic-compass/indicated-heading-deg",
                                "/instrumentation/slip-skid-ball/indicated-slip-skid",
                                "/instrumentation/turn-indicator/indicated-turn-rate",
                                "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                                "/controls/flight/aileron",
                                "/controls/flight/elevator",
                                "/controls/flight/rudder",
                                "/controls/flight/flaps",
                                "/controls/engines/engine/throttle",
                                "/engines/engine/rpm"};

    BindedSymbolMap* symap = new BindedSymbolMap(bindPaths); //will be connected to data server and flight server
    Expressioner* expressioner = new Expressioner(symap);
    map<string, Expression*> commandsDictionary = {{"openDataServer",new OpenDataServerCommand(symap, expressioner)},
                                                   {"connect",new ConnectCommand(symap, expressioner)},
                                                   {"print", new PrintCommand(expressioner)},
                                                   {"var", new VarCommand(symap, expressioner)},
                                                   {"=", new AssignmentCommand()},
                                                   {"bind", new BindCommand(expressioner, symap)},
                                                   {"{", new StartSetExpression()},
                                                   {"}", new EndSetExpression()}};
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