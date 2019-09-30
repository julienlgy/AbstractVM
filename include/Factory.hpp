/*
** EPITECH PROJECT, 2018
** CPP_abstractvm_2018
** File description:
** factory header
*/

#ifndef _FACTORY_HPP_
#define _FACTORY_HPP_
#include "IOperand.hpp"

class Factory
{
    private:
        IOperand* createInt8(const std::string& value);
        IOperand* createInt16(const std::string& value);
        IOperand* createInt32(const std::string& value);
        IOperand* createFloat(const std::string& value);
        IOperand* createDouble(const std::string& value);
        IOperand* createBigDecimal(const std::string& value);
        Factory();
    public:
        static IOperand* createOperand(eOperandType type , const std::string& value);
};

#endif
