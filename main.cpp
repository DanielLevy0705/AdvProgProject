

#include "Inputer.h"
#include "lexer.h"

int main() {
    DataServer dataServer;
    TableMap table = TableMap(dataServer); //will be connected to data server and flight server
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
        expressioner.push(parser.parse(lexer.lex(inputer.next())));
        expressioner.next().calculate();
    }
}


class ConnectDataServerCommand {
    DataServer dataServer;
    Expressioner Expressioner;

    execute() {
        Expression ip = Expressioner.next();
        Expression port = Expressioner.nextMathamethical(line);
        dataServer.connect(Expressioner.parse(argA), Expressioner.parse(argB))
    }
}