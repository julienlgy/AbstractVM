//
// Created by vincent on 11/01/19.
//

#include "../include/Stack.hpp"

using namespace std;

Stack::Stack()
{
    instructions.clear();
    operands.clear();
}

Stack::~Stack()
{
    instructions.clear();
    operands.clear();
}

Stack *Stack::getStack()
{
    if (!singleton)
        singleton = new Stack();
    return singleton;
}

Stack* Stack::singleton = nullptr;