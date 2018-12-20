//
// Created by fatuity on 12/20/18.
//

#ifndef PROJ1_PARSER_H
#define PROJ1_PARSER_H


#ifndef PARSER_H
#define PARSER_H

#include <list>
#include <map>

#include "Expression.h"
#include "Lexer.h"

using namespace std;

class Parser {
    Lexer lexer;
    Inputer inputer;
    DataTable *table;
    bool isPacketGetterON;
    map<string, Expression &> dictionary;

    Line getMathLine(Line &line) {
        Line mathExp;
        int i = 0;
        while (!line.empty()) {
            //if theres a number and then no operators its the end of an expression.
            if (isNum(line[0]) && !isOpr(line[1])) {
                mathExp.addWord(line.popFirst());
                return mathExp;
            }
            //if theres a symbol and no operators its the end of an expression.
            if (symbolMap->exist(line[0]) && !isOpr(line[1])) {
                string val = to_string(symbolMap[line.popFirst()].getValue());
                mathExp.addWord(val);
                return mathExp;
            }
            if (line[i] == ",") {
                line.popFirst();
                continue;
            }
            //if the word is an operator.
            if (isOpr(line[i])) {
                //if the expression ended with an operator throw exception.
                if (i = line.size() - 1) {
                    throw "Error: illegal expression : " + line[i];
                }
                //if the next is not a number and not a "-" the expression is illegal.
                if ((!isNum(line[1])) && (line[1] != "-") && (!symbolMap->exist(line[1]))) {
                    throw "Error: illegal line : " + line[i] + " " + line[i + 1];
                }
                //if its "-" check if its neg or if its subtraction.
                if (line[i] == "-") {
                    if (isNum(line[1]) && (!(mathExp.back() == ")") && !isNum(mathExp.back()))) {
                        string neg = line.popFirst() + line.popFirst();
                        mathExp.addWord(neg);
                        continue;
                    }
                    //*****************fix the problem of -(3+5)***********************
                }
            }
            //if its not one of the cases above, add to the current exp and continue the loop.
            mathExp.addWord(line.popFirst());
        } //end of while loop
        return mathExp;
    }

    Line shuntingYard(Line &line) {

    }

    bool isNum(string word) {
        bool dotCount = false;
        for (int i = 0; i < word.size(); i++) {
            //the char is not a digit
            if (!isdigit(word[i])) {
                //check if its a dot (and if its the only dot)
                if (i != 0 && word[i] == '.' && dotCount == false) {
                    dotCount = true;
                    continue;
                }
                return false;
            }
        }
        return true;
    }

    bool isOpr(const string &word) {
        return ((word == "+") && (word == "-") && (word == "*") &&
                (word == "/") && (word == "(") && (word == ")"));
    }


    Expression &parseMathLine(Line &line) {
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
        isPacketGetterON = false;
    }

public:
    Parser(DataTable *table) {
        lexer = Lexer();
        inputer = Inputer();
    }

    list<Expression &> next() {
        Line line = lexer.lexer(inputer.next());
        list<Expression &> expList;
        while (!line.empty()) {
            Line temp;
            string word = line.popFirst();
            if (dictionary.count(word) > 0) {
                //if the word is recognized by the map add it to list
                expList.emplace_front(dictionary[word]);
            } else if (isNum(word) || isOpr(word) || symbolMap->exist(word) || word == "(") {
                //if its the begginig of maths exp
                expList.emplace_back(parseMathLine(getMathLine(line)));
            } else if (isStringWord(word)) {
                //if its a word in commas "____"
                expList.emplace_back(StringExpression(word));
            } else if (isLetters(word)) {
                //if its letters can emphsaize new name for var
                expList.emplace_back(newExpression(word));
            } else if (word == "{") {
                expList.emplace_back(getCommandPacket());
            } else if (word == "}" && isPacketGetterON) {
                expList.emplace_back(newExpression(word));
            } else {
                throw "Error: illegal expression: " + word;
            };

        }
        return expList;
    }

};

#endif PARSER_H


#endif //PROJ1_PARSER_H
