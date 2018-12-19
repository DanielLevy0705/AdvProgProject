

#include "Inputer.h"
#include "lexer.h"

int main() {
    DataServer dataServer;
    SymbolMap symbols = TableMap(dataServer); //will be connected to data server and flight server
    Expressioner expressioner;
    Expressioner.add(map<string, Expression> = {
            {"var",VarCommand(&expressioner, table)},
            {"startDataServer",DSCommand(&expressioner, dataServer)},
            {"connect",ConnectCommend(&expressioner, table)},
            {"=",AssignCommend(&expressioner, table)},
            {"+",PlusExp(&expressioner)},
            {"num",NumExp(&expressioner)}
    };

    while (true) {
        expressioner.popNext().calculate();
    }
}