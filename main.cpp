
#include "ProgramTools.h"
#include "Commands.h"
#include "Expressions.h"
#include "SetExpression.h"
#include "ExitCommand.h"
#include "IfCommand.h"
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

    BindedSymbolMap *symap = new BindedSymbolMap(bindPaths); //will be connected to data server and flight server
    Expressioner *expressioner = new Expressioner(symap);
    map<string, Expression *> commandsDictionary = {{"openDataServer", new OpenDataServerCommand(symap, expressioner)},
                                                    {"connect", new ConnectCommand(symap, expressioner)},
                                                    {"print", new PrintCommand(expressioner)},
                                                    {"var", new VarCommand(symap, expressioner)},
                                                    {"=", new AssignmentCommand()},
                                                    {"bind", new BindCommand(expressioner, symap)},
                                                    {"{", new StartSetExpression()},
                                                    {"}", new EndSetExpression()},
                                                    {"exit", new ExitCommand(expressioner)},
                                                    {"if", new IfCommand(expressioner)}};
    expressioner->initiate(commandsDictionary);
    while (expressioner->on()) {
        try {
            Expression *exp = expressioner->popNext();
            if (exp != nullptr) {
                exp->calculate();
            }

        } catch (const string &errMsg) {
            cout << errMsg << endl;
        } catch (...) {
            //unexpected exception has occurred. need to fix this and exit the program properly.
            cout << "Error : unexpected exception has occurred";
        }
    }
    delete symap;
    delete expressioner;
}