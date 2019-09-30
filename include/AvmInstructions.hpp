/*
** EPITECH PROJECT, 2018
** CPP_abstractvm_2018
** File description:
** instructions class
*/

#ifndef CPP_ABSTRACTVM_2019_AVMINSTRUCTIONS_HPP
#define CPP_ABSTRACTVM_2019_AVMINSTRUCTIONS_HPP

#include <string>
#include <list>
#include <iostream>
#include <algorithm>

typedef enum instructionsName
{
    PUSH = 1,
    POP = 2,
    CLEAR = 3,
    DUP = 4,
    SWAP = 5,
    DUMP = 6,
    ASSERT = 7,
    ADD = 8,
    SUB = 9,
    MUL = 10,
    DIV = 11,
    MOD = 12,
    PRINT = 13,
    LOAD = 14,
    STORE = 15,
    EXIT = 98,
    WRONG_COMMAND = 99,
} instructionsName;

class AvmInstructions {
    public:
        AvmInstructions();

        AvmInstructions(instructionsName instruction);

        AvmInstructions(instructionsName instruction, std::string value);

        instructionsName getInstruction() const {
            return (instruction);
        }

        std::string getValue() const {
            return (value);
        }

        void  setValue(std::string value) {
            this->value = value;
        }

        void setInstruction(instructionsName instruction) {
            this->instruction = instruction;
        }

        instructionsName searchForInstruction(std::string instruction);
    private:
        instructionsName instruction;
        std::string value;
};
#endif //CPP_ABSTRACTVM_2019_AVMINSTRUCTIONS_HPP
