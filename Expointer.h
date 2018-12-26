//
// Created by elronbandel on 12/26/18.
//

#ifndef EXPOINT_H
#define EXPOINT_H

#include <memory>


class Expression;

using namespace std;

//typedef shared_ptr<Expression> Expointer;
typedef shared_ptr<Expression> Expointer;

Expointer newExpointer(Expression* exp) {
    return shared_ptr<Expression>(exp);
}

#endif //UNTITLED4_EXPOINT_H
