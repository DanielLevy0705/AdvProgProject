//
// Created by elronbandel on 12/23/18.
//

#include "StringsLibrary.h"

string getInnerString(char start,const string& s, char end)  {
    bool rec = false;
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == end && rec)
            return res;
        if (rec)
            res = res + s[i];
        if (s[i] == start)
            rec = true;
    }
    return res;
}

static vector<string> split(const string& s, char delimiter){
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}