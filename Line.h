//
// Created by fatuity on 12/18/18.
//

#ifndef PROJ1_LINE_H
#define PROJ1_LINE_H


#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class Line {
    vector<string> line;
public:
    explicit Line(vector<string> newLine) {
        line = newLine;
    }

    Line() {}

    string first() {
        if (line.empty()) {
            throw "line is empty";
        }
        return line.at(0);
    }

    string popFirst() {
        if (line.empty()) {
            throw "line is empty";
        }
        string retVal = line.at(0);
        assert(!line.empty());
        line.erase(line.begin());
        return retVal;
    }

    string operator[](size_t n) {
        if (line.size() - 1 < n) {
            return nullptr;
        }
        return line.at(n);
    }

    int size() {
        return line.size();
    }

    bool has(int n) {
        return (!line.empty());
    }

    void addWord(string newWord) {
        line.push_back(newWord);
    }

    bool empty() {
        return line.empty();
    }

    string back() {
        if (line.empty()) {
            return nullptr;
        }
        return line.back();
    }
};


#endif //PROJ1_LINE_H
