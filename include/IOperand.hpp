/*
** EPITECH PROJECT, 2018
** CPP_abstractvm_2018
** File description:
** IOperand header
*/

#ifndef _IOPERAND_HPP_
#define _IOPERAND_HPP_

#include <string>

typedef enum eOperandType
{
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    BigDecimal
} eOperandType;

class IOperand
{
    public:
        virtual std::string toString() const = 0;

        virtual eOperandType getType() const = 0;
        virtual int getPrecision() const = 0;
        virtual IOperand* operator+(const IOperand &rhs) const = 0;
        virtual IOperand* operator-(const IOperand &rhs) const = 0;
        virtual IOperand* operator*(const IOperand &rhs) const = 0;
        virtual IOperand* operator/(const IOperand &rhs) const = 0;
        virtual IOperand* operator%(const IOperand &rhs) const = 0;

        virtual ~IOperand() {}
};

#endif
