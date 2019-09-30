//
// Created by vincent on 11/01/19.
//

#ifndef CPP_ABSTRACTVM_2019_STACK_HPP
#define CPP_ABSTRACTVM_2019_STACK_HPP

#include <list>
#include "IOperand.hpp"
#include "AvmInstructions.hpp"

using namespace std;

class Stack {

    static Stack *singleton;

    private:
        Stack();

    public:
        ~Stack();
        static Stack *getStack();
        list<AvmInstructions *> instructions;
        list<IOperand *> operands;

};


#endif //CPP_ABSTRACTVM_2019_STACK_HPP
