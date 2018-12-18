#ifndef PROJ1_LEXER_H
#define PROJ1_LEXER_H


#include "Line.h"

class Lexer {
    Line lexer(string input) {
        vector<string> vec;
        Line line = Line(vec);
        int idx = 0;
        string newWord, substring;
        bool newWordAddition = false;
        while (idx == input.size()) {

            if (isspace(input[idx])) {
                if (newWordAddition) {
                    line.addWord(newWord);
                    newWordAddition = false;
                    newWord = "";
                }
            } else if (!isalpha(input[idx]) && !isdigit(input[idx])) {
                if (newWordAddition) {
                    line.addWord(newWord);
                    newWordAddition = false;
                    newWord = "";
                }
                newWord += input[idx];
                line.addWord(newWord);
                newWord = "";
            } else {
                newWord += input[idx];
                newWordAddition = true;
            }
            idx++;
        }
    }
};


#endif //PROJ1_LEXER_H
