/*
** EPITECH PROJECT, 2018
** CPP_abstractvm_2018
** File description:
** Operand header
*/

#include "Operand.hpp"
#include "Factory.hpp"
#include "Exceptions.hpp"

#include <iostream>
#include <iomanip>
#include <math.h>
#include <float.h>
#include <string>
#include <sstream>
#include <limits.h>

Operand::Operand(eOperandType ope_type, int ope_pres, std::string const &value)
{
    if (this->is_valid_number(ope_type, value)) {
        this->val = value;
        this->type = ope_type;
        this->precision = ope_pres;
    } else {
        cout << "Error : " << ope_type << " > " << value << " " << ope_pres << endl;
        throw Exceptions("Invalid value");
    }
}

Operand::~Operand() {}

int Operand::getPrecision() const {
  return (precision);
}
eOperandType Operand::getType() const {
  return (type);
}
std::string Operand::toString() const {
  return (val);
}

IOperand* Operand::operator+(const IOperand &rhs) const
{
    int precision = (this->getPrecision() >= rhs.getPrecision()) ? this->getPrecision() : rhs.getPrecision();
    eOperandType otype = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();

    std::stringstream ss (std::stringstream::out);
    if (otype < Float) {
        long long r = std::stoll(this->toString()) + std::stoll(rhs.toString());
        ss << r;
    } else {
        long double r = std::stold(this->toString()) + std::stold(rhs.toString());
        ss << std::setprecision(precision) << r;
    }
    return (Factory::createOperand(otype, ss.str()));

}
IOperand* Operand::operator-(const IOperand &rhs) const
{
    int precision = (this->getPrecision() >= rhs.getPrecision()) ? this->getPrecision() : rhs.getPrecision();
    eOperandType otype = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();

    std::stringstream ss (std::stringstream::out);
    if (otype < Float) {
        long long r = std::stoll(this->toString()) - std::stoll(rhs.toString());
        ss << r;
    } else {
        long double r = std::stold(this->toString()) - std::stold(rhs.toString());
        ss << std::setprecision(precision) << r;
    }
    return (Factory::createOperand(otype, ss.str()));
}
IOperand* Operand::operator*(const IOperand &rhs) const
{
    int precision = (this->getPrecision() >= rhs.getPrecision()) ? this->getPrecision() : rhs.getPrecision();
    eOperandType otype = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();

    std::stringstream ss (std::stringstream::out);
    if (otype < Float) {
        long long r = std::stoll(this->toString()) * std::stoll(rhs.toString());
        ss << r;
    } else {
        long double r = std::stold(this->toString()) * std::stold(rhs.toString());
        ss << std::setprecision(precision) << r;
    }
    return (Factory::createOperand(otype, ss.str()));
}

IOperand* Operand::operator/(const IOperand &rhs) const
{
    int precision = (this->getPrecision() >= rhs.getPrecision()) ? this->getPrecision() : rhs.getPrecision();
    eOperandType otype = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();

    if (std::stold(rhs.toString()) == 0)
        throw Exceptions("Division by 0");

    std::stringstream ss (std::stringstream::out);
    if (otype < Float) {
        long long r = std::stoll(this->toString()) / std::stoll(rhs.toString());
        ss << r;
    } else {
        long double r = std::stold(this->toString()) / std::stold(rhs.toString());
        ss << setprecision(precision) << r;
    }
    return (Factory::createOperand(otype, ss.str()));
}

IOperand* Operand::operator%(const IOperand &rhs) const
{
    int precision = (this->getPrecision() >= rhs.getPrecision()) ? this->getPrecision() : rhs.getPrecision();
    eOperandType otype = (this->getType() > rhs.getType()) ? this->getType() : rhs.getType();

    if (std::stold(rhs.toString()) == 0)
        throw Exceptions("Modulo by 0");

    std::stringstream ss(std::stringstream::out);
    if (otype < Float)
    {
      long long r = std::stoll(this->toString()) % std::stoll(rhs.toString());
      ss << r;
    }
    else
    {
      long double r = fmod(std::stold(this->toString()), std::stold(rhs.toString()));
      ss << std::setprecision(precision) << r;
    }
    return (Factory::createOperand(otype, ss.str()));

}

bool Operand::is_valid_number(eOperandType type, std::string const &value)
{
    std::string::const_iterator it = value.begin();
    bool hasVirgule = false;
    int aftVirgule = 0;

    if (*(it) == '-' || *(it) == '+')
        it++;

    while (it != value.end()) {
        if (type < Float) {
            if (!isdigit((*it)))
              return (false);
        } else {
            if ((*it) == '.' && !hasVirgule) hasVirgule = !hasVirgule;
            else if ((*it) == '.' && hasVirgule) return (false);
            else {
                if (!isdigit((*it)))
                    return (false);
                if (hasVirgule)
                    aftVirgule++;
            }
        }
        it++;
    };
    switch (type) {
        case Float:
            return ( (Operand::precisionFloat() < aftVirgule) ? false : true);
        case Double:
            return ( (Operand::precisionDouble() < aftVirgule) ? false : true);
        case BigDecimal:
            return ( (Operand::precisionBigDecimal() < aftVirgule) ? false : true);
        default:
            return (true);
    }
}
