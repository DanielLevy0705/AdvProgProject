//created by: elron bandel and daniel levy

#ifndef INPUTER_H
#define INPUTER_H

#include <queue>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/****
 * Iputer - handle the input from command line or files
 *
 ***/
class Inputer {
    queue<string> que;
public:
//load - function that add to the queue more command lines from file
    void load(string path) {
        ifstream sourceFile(path);
        string line;
        if (sourceFile.is_open()) {
            while (!sourceFile.eof()) {
                getline(sourceFile, line);
                que.push(line);
            }
            sourceFile.close();
            que.push("exit");
        } else {
            que.push("exit");
            throw string("Error: file not found!");
        }


    }
//next - function that loads the next line from the que or the user
    string next() {
        if (que.empty()) {
            string s;
            getline(cin, s);
            return s;
        } else {
            string s = que.front();
            que.pop();
            return  s;
        }
    }
};


#endif// INPUTER_H
