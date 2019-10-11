#ifndef COMMAND_H
#define COMMAND_H


#include <string>

using namespace std;

class Command {
public:
    virtual double execute() const = 0;

    virtual string getString() const = 0;

    virtual ~Command() {}
};

#endif //UNTITLED4_COMMAND_H
