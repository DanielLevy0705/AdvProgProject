//
// Created by elronbandel on 12/23/18.
//

#ifndef STRINGSLIBRARY_H
#define STRINGSLIBRARY_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;

static vector<string> split(const string& s, char delimiter);

string getInnerString(char start, const string& s, char end);



#endif //STRINGSLIBRARY_H
