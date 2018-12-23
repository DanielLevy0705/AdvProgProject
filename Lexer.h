#ifndef PROJ1_LEXER_H
#define PROJ1_LEXER_H


#include "Line.h"

class Lexer {
public:
    Line lexer(string input) {
        vector<string> vec;
        Line line = Line(vec);
        int idx = 0;
        string newWord, substring;
        bool newWordAddition = false, addAnotherChar = false;
        //run for every char of the line.
        while (idx != input.size()) {
            //check if the char is space, if it is, add the last word and nullify the next word.
            if (isspace(input[idx])) {
                if (newWordAddition) {
                    line.addWord(newWord);
                    newWordAddition = false;
                    newWord = "";
                }
                //if its not alphabet,number or a dot, its an operator.
            } else if (!isalpha(input[idx]) && !isdigit(input[idx]) &&
                       (input[idx] != '.') && (input[idx] != '\"')) {
                if (newWordAddition) {
                    //add new word and nullify the next.
                    line.addWord(newWord);
                    newWordAddition = false;
                    newWord = "";
                }
                //check for two chars size bool operators.
                if ((idx < input.size() - 1) && (input[idx] == '!' || input[idx] == '=' ||
                                                 input[idx] == '<' || input[idx] == '>')) {
                    if (input[idx + 1] == '=') {
                        addAnotherChar = true;
                    } else {
                        addAnotherChar = false;
                    }
                }
                newWord += input[idx];
                //we want the full boolean expression.
                if (addAnotherChar) {
                    idx++;
                    newWord += input[idx];
                }
                //add the operator then nullify the next word.
                line.addWord(newWord);
                newWord = "";
                //if its a digit or a letter add it to the word, and notify that youre buliding a word.
            } else {
                newWord += input[idx];
                newWordAddition = true;
            }
            idx++;
        }
        //add the last word into the line
        if (!newWord.empty()) {
            line.addWord(newWord);
        }
        return line;
    }
};


#endif //PROJ1_LEXER_H