//
// Created by elronbandel on 12/18/18.
//
#ifndef INPUTER_H
#define INPUTER_H
//
#include <queue>
#include <string>
using namespace std;
class Inputer {
    queue<string> que;

//load - function that add to the queue more command lines from file
    void load(string path) {
        ifstream sourceFile(path);
        string line;
        if (sourceFile.is_open()) {
            while (!sourceFile.eof()) {
                getline(sourceFile, line);
                que.push_back(line);
            }
            sourceFile.close();
        }
    }
//next - function that loads the next line from the que or the user
    string next() {
        if (que.empty()) {
            string s;
            return s << cin
        } else {
            return que.pop_front();
        }
    }
};
//
#endif INPUTER_H
