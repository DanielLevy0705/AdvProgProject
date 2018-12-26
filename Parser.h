//
// Created by fatuity on 12/20/18.
//



#ifndef PARSER_H
#define PARSER_H

#include <map>
#include <stack>
#include "Line.h"
#include "Expression.h"
#include "Lexer.h"
#include "Div.h"
#include "Mult.h"
#include "Number.h"
#include "Minus.h"
#include "Plus.h"
#include "Neg.h"
#include "Inputer.h"
#include "Expressioner.h"
#include "CommandExpression.h"
#include "StringExpression.h"
#include "CommandSet.h"
#include "SetExpression.h"
#include "ConditionExpression.h"


//#include "ValueExpression.h"

class Expressioner;

using namespace std;

class Parser {
    Lexer lexer;
    Inputer inputer;
    BindedSymbolMap *symap;
    Expressioner *expressioner;
    //need to mark unary minus with a string that won't be in the expression.
    const string neg = "$";
    map<string, Command *> dictionary;
public:

    Parser(BindedSymbolMap *symbolMap, Expressioner *exprer) {
        symap = symbolMap;
        expressioner = exprer;
        lexer = Lexer();
        inputer = Inputer();
    }



    void initiate(map<string, Command *> dict) {
        dictionary = dict;
    }

    Line getMathLine(Line *line);

    Expointer applyOp(Expointer left, Expointer right, string op);

    int precendance(string opr);

    void shuntingYardHelper(stack<string> &oprs, stack<Expointer > &values);

    Expointer shuntingYard(Line exp);

    bool isNum(string word);

    bool isOpr(const string &word);

    CommandSet* getCommandSet() {
        //create the required command packet
        CommandSet* set = new CommandSet(expressioner);
        //get the next line from parser
        list<Expointer > temp = next();
        while (temp.back()->getType() != typeid(EndSetExpression)) {
            set->pushLine(temp);
            temp = next();
        }
        temp.pop_back();
        if (temp.size() > 0) {
            set->pushLine(temp);
        }
        return set;
    }

    bool isLegalVarName(const string &word);

    bool isStringWord(const string &word);

    bool isCondition(const string &word);

    bool isIp(const string &word);

    Expointer getConditionExpression(list<Expointer > &expList, Line *line);

public:


    list<Expointer > next();
};

#endif //PARSER_H
