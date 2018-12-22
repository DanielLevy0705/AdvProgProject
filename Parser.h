//
// Created by fatuity on 12/20/18.
//

#ifndef PROJ1_PARSER_H
#define PROJ1_PARSER_H


#ifndef PARSER_H
#define PARSER_H

#include <list>
#include <map>
#include <stack>
#include "Expression.h"
#include "Lexer.h"
#include "Div.h"
#include "Mult.h"
#include "Number.h"
#include "Minus.h"
#include "Plus.h"
#include "Neg.h"
#include "Inputer.h"
#include "BindedSymbolMap.h"

using namespace std;

class Parser {
    Lexer lexer;
    Inputer inputer;
    BindedSymbolMap* symap;
    bool isPacketGetterON;
    //need to mark unary minus with a string that won't be in the expression.
    const string neg = "$";
    map<string, Expression*> dictionary;
public:
    
    Parser(map<string, Expression*> dict, BindedSymbolMap* symbolMap) {
        dictionary = dict;
        lexer = Lexer();
        inputer = Inputer();
        isPacketGetterON = false;
    }

    Line getMathLine(Line *line) {
        Line mathExp;
        int i = 0;
        while (!line->empty()) {
            //if theres a number and then no operators its the end of an expression.
            if (isNum((line->operator[](0))) && (!isOpr(line->operator[](1)) ||
                                                 line->operator[](1) == ",")) {
                mathExp.addWord(line->popFirst());
                return mathExp;
            }
            //if theres a symbol and no operators its the end of an expression.
            if (symap->exist(line->operator[](0)) && (!isOpr(line->operator[](1)) ||
                                                          line->operator[](1) == ",")) {
                string val = to_string(symap[line->popFirst()].getValue());
                mathExp.addWord(val);
                return mathExp;
            }
            if (line->operator[](0) == ",") {
                line->popFirst();
                continue;
            }
            //if the word is an operator.
            if (isOpr(line->operator[](0))) {
                //if the expression ended with an operator throw exception.
                if (i = line->size() - 1) {
                    throw "Error: illegal expression : " + line->operator[](0);
                }
                //if the next is not a number and not a "-" the expression is illegal.
                if ((!isNum(line->operator[](1)))
                    && (!symap->exist(line->operator[](1)))) {
                    if (line->operator[](1) != "-") {
                        throw "Error: illegal line : " + line->operator[](0) + " " + line->operator[](1);
                    }
                    //if the next char is an unary minus and the size > 2.
                    if (line->size() > 2) {
                        //if the next char does not fit to an unary minus throw exception.
                        if (line->operator[](2) != "(" &&
                            !isNum(line->operator[](2)) &&
                            (!symap->exist(line->operator[](2)))) {
                            throw "Error: illegal line";
                        }
                    }
                }
                //if its "-" check if its unary.
                if (line->operator[](0) == "-") {
                    if ((mathExp.empty()) || ((mathExp.back() != ")") && isOpr(mathExp.back()))) {
                        line->popFirst();
                        mathExp.addWord(neg);
                        continue;
                    }
                }
            }
            //if its not one of the cases above, add to the current exp and continue the loop.
            mathExp.addWord(line->popFirst());
        } //end of while loop
        return mathExp;
    }

    Expression *applyOp(Expression *left, Expression *right, string op) {
        if (op == "+") {
            return new Plus(op, left, right);
        } else if (op == "-") {
            new Minus(op, left, right);
        } else if (op == "*") {
            new Mult(op, left, right);
        } else if (op == "/") {
            new Div(op, left, right);
        } else if (op == neg) {
            new Neg(op, left);
        }
    }

    int precendance(string opr) {
        if (opr == "+" || opr == "-") {
            return 1;
        }
        if (opr == "*" || opr == "/") {
            return 2;
        }
        if (opr == neg) {
            return 3;
        }
        return 0;
    }

    void shuntingYardHelper(stack<string> &oprs, stack<Expression *> &values) {
        string op;
        Expression *leftVal, *rightVal;
        if (oprs.top() == neg) {
            rightVal = values.top();
            values.pop();

            op = oprs.top();
            oprs.pop();

            values.push(applyOp(nullptr, rightVal, op));
        } else {
            rightVal = values.top();
            values.pop();

            leftVal = values.top();
            values.pop();

            op = oprs.top();
            oprs.pop();

            values.push(applyOp(leftVal, rightVal, op));
        }
    }

    Expression *shuntingYard(Line exp) {
        stack<Expression *> values;
        stack<string> oprs;
        string op;
        Expression *rightVal;
        Expression *leftVal;
        //run all over the expression.
        for (int i = 0; i < exp.size(); i++) {
            //if its opening braces push to oprators stack.
            if (exp[i] == "(") {
                oprs.push(exp[i]);
                //if its a number push to values stack.
            } else if (isNum(exp[i])) {
                values.push(new Number(exp[i]));
                //if its closing braces pop all operators to values stack.
            } else if (exp[i] == ")") {
                while (!oprs.empty() && oprs.top() != "(") {
                    shuntingYardHelper(oprs, values);
                }
                if (!oprs.empty()) {
                    //pop opening braces.
                    oprs.pop();
                }
            } else {
                while (!oprs.empty() && precendance(oprs.top()) >= precendance(exp[i])) {
                    shuntingYardHelper(oprs, values);
                }
                oprs.push(exp[i]);
            }
        }
        while (!oprs.empty()) {
            shuntingYardHelper(oprs, values);
        }
        return values.top();
    }

    bool isNum(string word) {
        bool dotCount = false;
        for (int i = 0; i < word.size(); i++) {
            //the char is not a digit
            if (!isdigit(word[i])) {
                //check if its a dot (and if its the only dot)
                if (i != 0 && word[i] == '.' && !dotCount) {
                    dotCount = true;
                    continue;
                }
                return false;
            }
        }
        return true;
    }

    bool isOpr(const string &word) {
        return ((word == "+") || (word == "-") || (word == "*") ||
                (word == "/") || (word == "(") || (word == ")") || (word == ","));
    }

    void getCommandPacket() {
        isPacketGetterON = true;
        //create the required command packet
        CommandPacket cp;
        //get the next line from parser
        list<Expression> temp = next();
        while (temp.back().toString() != "}") {
            cp.push(temp);
            temp = next();
        }
        isPacketGetterON = false;
    }

public:


    list<Expression*> next() {
        Line line = lexer.lexer(inputer.next());
        list<Expression*> expList;
        while (!line->empty()) {
            Line temp;
            string word = line->popFirst();
            if (dictionary.count(word) > 0) {
                //if the word is recognized by the map add it to list
                expList.emplace_front(dictionary[word]);
            } else if (isNum(word) || isOpr(word) || symap->exist(word) || word == "(") {
                //if its the begginig of maths exp
                expList.emplace_back(shuntingYard(getMathLine(line)));
//            } else if (isStringWord(word)) {
//                //if its a word in commas "____"
//                expList.emplace_back(StringExpression(word));
//            } else if (isLetters(word)) {
//                //if its letters can emphsaize new name for var
//                expList.emplace_back(newExpression(word));
//            } else if (word == "{") {
//                expList.emplace_back(getCommandPacket());
//            } else if (word == "}" && isPacketGetterON) {
//                expList.emplace_back(newExpression(word));
            } else {
                throw "Error: illegal expression: " + word;
            };

        }
        return expList;
    }

};

#endif PARSER_H


#endif //PROJ1_PARSER_H
