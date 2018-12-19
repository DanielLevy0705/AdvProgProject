

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
class WhileCommand {
    Expressioner expressioner;
    queue<Expressioner> que;
    calculate() {
        Line line = lexer.lex(inputer.next());
        while (!line.contain("}")) {
            que.push(Exprresioner(parser.parse(line)))
            line = lexer.lex(inputer.next())
        }
        que.push(Exprresioner(parser.parse(line)))
        while (condition.calculate()) {
            queue<Expressioner> copy = que.copy();
            while (!copy.empty()) {
                Expressioner temp = copy.pop();
                while (!temp.empty())
                    temp.next().calculate();
            }
        }
    }

};

class ConnectDataServerCommand {
    DataServer dataServer;
    Expressioner Expressioner;

    execute() {
        Expression ip = Expressioner.next();
        Expression port = Expressioner.nextMathamethical(line);
        dataServer.connect(Expressioner.parse(argA), Expressioner.parse(argB))
    }
}