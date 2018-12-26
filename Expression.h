#ifndef PROJ1_EXPRESSION_H
#define PROJ1_EXPRESSION_H



#include <typeinfo>
#include <string>

using namespace std;

class Expression {

public:

    virtual double calculate() const = 0;

    virtual string getString() const = 0;

    virtual const type_info& getType() const = 0;


};


#endif //PROJ1_EXPRESSION_H