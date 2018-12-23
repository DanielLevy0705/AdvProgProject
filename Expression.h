#ifndef PROJ1_EXPRESSION_H
#define PROJ1_EXPRESSION_H


#include <string>
#include "Printable.h"
#include <typeinfo>


using namespace std;

class Expression : public Printable {

public:

    virtual double calculate() const = 0;

    virtual string getString() const = 0;


};


#endif //PROJ1_EXPRESSION_H