#ifndef ASSIGNMENTCOMMAND_H
#define ASSIGNMENTCOMMAND_H

#include "Command.h"


class AssignmentCommand : public Command {
public:
    AssignmentCommand() {}

    // a Value type expression will handle the assignment.
    string getString() const override {
        throw string("Error: '=' can be put only after memory stored value");
    }

    double execute() const override {
        throw string("Error: '=' can be put only after memory stored value");
    }
};

#endif //UNTITLED4_ASSIGNMENTCOMMAND_H
