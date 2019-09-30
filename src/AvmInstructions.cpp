//
// Created by julien on 11/01/19.
//

#include "AvmInstructions.hpp"

#define stringify( name ) # name

using namespace std;

AvmInstructions::AvmInstructions()
{

}

AvmInstructions::AvmInstructions(instructionsName instruction)
{
    this->instruction = instruction;
    this->value = "NaN";
}

AvmInstructions::AvmInstructions(instructionsName instruction, std::string value)
{
    this->instruction = instruction;
    this->value = value;
}

instructionsName AvmInstructions::searchForInstruction(std::string instruction)
{
    if (instruction == "push")
        return (PUSH);
    if (instruction == "pop")
        return (POP);
    if (instruction == "clear")
        return (CLEAR);
    if (instruction == "dup")
        return (DUP);
    if (instruction == "swap")
        return (SWAP);
    if (instruction == "dump")
        return (DUMP);
    if (instruction == "assert")
        return (ASSERT);
    if (instruction == "add")
        return (ADD);
    if (instruction == "sub")
        return (SUB);
    if (instruction == "mul")
        return (MUL);
    if (instruction == "div")
        return (DIV);
    if (instruction == "mod")
        return (MOD);
    if (instruction == "load")
        return (LOAD);
    if (instruction == "store")
        return (STORE);
    if (instruction == "print")
        return (PRINT);
    if (instruction == "exit")
        return (EXIT);
    return (WRONG_COMMAND);
}
