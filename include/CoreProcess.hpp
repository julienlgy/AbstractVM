/*
** EPITECH PROJECT, 2018
** CPP_abstractvm_2018
** File description:
** Core Process header
*/

#ifndef CPP_ABSTRACTVM_2018_COREPROCESS_HPP
#define CPP_ABSTRACTVM_2018_COREPROCESS_HPP

#include <string>
#include "Stack.hpp"
#include "Operand.hpp"
#include "Factory.hpp"

class CoreProcess {
    public:
        static void readMemory();
    private:
        static bool doPush(std::string instruction);
        static bool doPop();
        static bool doClear();
        static bool doDup();
        static bool doSwap();
        static bool doDump();
        static bool doAssert(std::string instruction);
        static bool doPrint();
        static bool doLoad(std::string instruction);
        static bool doStore(std::string instruction);
        // Operand
        static bool doOperand(instructionsName name);
        // Functionnals
        static void executeCommand(AvmInstructions* instruction);
        static eOperandType geteOperandType(std::string type);
        // Registers
        static IOperand* registers[15];
};

#endif //CPP_ABSTRACTVM_2018_COREPROCESS_HPP
