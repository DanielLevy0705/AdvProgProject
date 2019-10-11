#ifndef UNTITLED4_EXITCOMMAND_H
#define UNTITLED4_EXITCOMMAND_H


#include "Command.h"
#include "Expressioner.h"

class ExitCommand : public Command {
    Expressioner *expressioner;
public:
    explicit ExitCommand(Expressioner *expnr) {
        expressioner = expnr;
    }

    virtual string getString() const {
        return "ExitCommand";
    }

    virtual double execute() const {
        expressioner->close();
        return 0;
    }
};


#endif //UNTITLED4_EXITCOMMAND_H
