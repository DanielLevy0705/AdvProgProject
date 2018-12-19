

#include "Inputer.h"
#include "lexer.h"

int main() {
    DataServer dataServer;
    TableMap table = TableMap(dataServer); //will be connected to data server and flight server
    Parser parser;
    parser.add(map<string, Expression> = {
            {"var",VarCommand(&parser, table)},
            {"startDataServer",DSCommand(&parser, dataServer)},
            {"connect",ConnectCommend(&parser, table)},
            {"=",AssignCommend(&parser, table)},
            {"+",PlusExp(&parser)},
            {"num",NumExp(&parser)}
    };

    while (true) {
        Line line = lexer.lex(inputer.next());
        string first = line.popFirst();
        parser.parse(first).calculate(line);
    }
}


class ConnectDataServerCommand {
    DataServer dataServer;
    Parser parser;

    execute() {
        Expression ip = parser.next();
        Expression port = parser.nextMathamethical(line);
        dataServer.connect(parser.parse(argA), parser.parse(argB))
    }
};

4+ 5 / 5

4 / 5 + 5

 + 5 / 5  4

  +

