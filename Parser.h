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
    bool isPacketGetterON;
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

    void getCommandPacket() {
        isPacketGetterON = true;
        //create the required command packet
        CommandPacket cp;
        //get the next line from parser
        list<Expression> temp = next();
        while (temp.back().toString() == "}") {
            cp.push(temp);
            temp = next();
        }
        isPacketGetterON = false
    }

public:
    Parser(DataTable* table) {
        lexer = Lexer();
        inputer = Inputer();
    }
    list<Expression&> next() {
        Line line = lexer.lexer(inputer.next());
        list<Expression&> expList;
        while (!line.empty()) {
            Line temp;
            string word = line.popFirst()
            if (dictionary.count(word) > 0) {
                //if the word is recognized by the map add it to list
                expList.emplace_front(dictionary[word]);
            } else if (isNum(word) || isOpr(word) || symbolMap->exist(word) || word == "(") {
                //if its the begginig of maths exp
                expList.emplace_back( parseMathLine(  getMathLine(word, line)));
            } else if (isStringWord(word)){
                //if its a word in commas "____"
                expList.emplace_back(StringExpression(word));
            } else if (isLetters(word)) {
                //if its letters can emphsaize new name for var
                expList.emplace_back(newExpression(word));
            } else if (word == "{") {
                expList.emplace_back(getCommandPacket());
            }  else if (word == "}" && isPacketGetterON) {
                expList.emplace_back(newExpression(word));
            }else {
                throw "Error: illegal expression: " + word;
            };

        }
        return expList;
    }

};

#endif PARSER_H
