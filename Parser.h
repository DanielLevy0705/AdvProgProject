//
// Created by fatuity on 12/20/18.
//



#ifndef PARSER_H
#define PARSER_H

#include <map>
#include <stack>
#include "Line.h"
#include "Expressions.h"
#include "Lexer.h"
#include "Div.h"
#include "Mult.h"
#include "Number.h"
#include "Minus.h"
#include "Plus.h"
#include "Neg.h"
#include "Inputer.h"
#include "Expressioner.h"

#include "StringExpression.h"


//#include "ValueExpression.h"

class Expressioner;
using namespace std;

class Parser {
    Lexer lexer;
    Inputer inputer;
    BindedSymbolMap* symap;
    Expressioner* expressioner;
    bool isPacketGetterON;
    //need to mark unary minus with a string that won't be in the expression.
    const string neg = "$";
    map<string, Expression*> dictionary;
public:
    
    Parser(BindedSymbolMap* symbolMap, Expressioner* exprer) {
        symap = symbolMap;
        expressioner = exprer;
        lexer = Lexer();
        inputer = Inputer();
        isPacketGetterON = false;
    }
    void initiate(map<string, Expression*> dict) {
        dictionary = dict;

    }

    Line getMathLine(Line *line);

    Expression *applyOp(Expression *left, Expression *right, string op);
    int precendance(string opr);

    void shuntingYardHelper(stack<string> &oprs, stack<Expression *> &values);
    Expression* shuntingYard(Line exp);

    bool isNum(string word);
    bool isOpr(const string &word);

//    void getCommandPacket() {
//        isPacketGetterON = true;
//        //create the required command packet
//        CommandPacket cp;
//        //get the next line from parser
//        list<Expression> temp = next();
//        while (temp.back().toString() != "}") {
//            cp.push(temp);
//            temp = next();
//        }
//        isPacketGetterON = false;
//    }
    bool isLegalVarName(const string& word);

    bool isIp(const string& word);

public:


    list<Expression*> next();
};

#endif //PARSER_H
