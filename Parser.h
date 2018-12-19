//
// Created by elronbandel on 12/19/18.
//

#ifndef PARSER_H
#define PARSER_H

#include <list>
#include <map>

#include "Expression.h"
using namespace std;
class Parser {
    Lexer lexer;
    Inputer inputer;
    DataTable* table;
    map <string, Expression&> dictionary;

    Line shuntingYard(Line line) {

    }
    bool isNum(string word) {

    }

    bool isOpr(const string& word) {

    }


    Expression& parseMathLine(Line line) {
        line = shuntingYard(line);
        //...
    }

public:
    Parser(DataTable* table) {
        lexer = Lexer();
        inputer = Inputer();
    }
    list<Expression&> next() {
        Line line = lexer.lex(inputer.next());
        list<Expression&> expList;
        while (!line.empty()) {
            Line temp;
            string word = line.popFirst()
            if (dictionary.count(word) > 0) {
                //if the word is recognized by the map add it to list
                expList.emplace_front(dictionary[word]);
            } else if (isNum(word) || isOpr(word) || table.exist(word) || word == "(") {
                //if its the begginig of maths exp
                expList.emplace_front(parseMathLine(getMathLine(word, line)));
            } else if (isStringWord(word)){
                //if its a word in commas "____"
                expList.emplace_front(StringExpression(word));
            } else if (isLetters(word)) {
                //if its letters can emphsaize new name for var
                expList.emplace_front(UnknownNameExpression(word));
            } else {
                throw "Error: ilegal expression: " + word;
            };

        }
        return expList;
    }

};

#endif PARSER_H
