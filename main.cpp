
#include "Inputer.h"
#include "lexer.h"

int main() {
    DataServer dataServer;
    ValTable table;
    Parser parser;
    parser.add("var",VarCommand(table));
    parser.add("startDataServer",DSCommand(dataServer));
    parser.add("connect",ConnectCommend(dataServer))
    parser.add("=",AssignCommend(table));
    parser.add("+",PlusExp());
    parser.add("num",NumExp());



    while (true) {
        parser.parse(lexer.lex(inputer.next())).execute();
    }
}