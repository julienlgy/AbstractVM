/*
** EPITECH PROJECT, 2018
** CPP_abstractvm_2018
** File description:
** OPERAND
*/

#ifndef _OPERAND_HPP_
#define _OPERAND_HPP_

#include "IOperand.hpp"
#include <string>

using namespace std;

class Operand : public IOperand
{
    public:
        Operand(eOperandType ope_type, int ope_pres, std::string const &value);
        ~Operand();
        int getPrecision() const;
        eOperandType getType() const;
        std::string toString() const;
        IOperand* operator+(const IOperand &rhs) const;
        IOperand* operator-(const IOperand &rhs) const;
        IOperand* operator*(const IOperand &rhs) const;
        IOperand* operator/(const IOperand &rhs) const;
        IOperand* operator%(const IOperand &rhs) const;

        static int precisionFloat() {return (7 );};
        static int precisionDouble() {return(15);};
        static int precisionBigDecimal() {return(200);};
    private:
        eOperandType type;
        std::string val;
        int precision;
        bool is_valid_number(eOperandType type, std::string const &value);
};
#endif
