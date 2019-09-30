/*
** EPITECH PROJECT, 2018
** CPP_abstractvm_2018
** File description:
** factory cpp
*/

#include "Factory.hpp"
#include "Operand.hpp"
#include "Exceptions.hpp"

#include <iostream>
#include <limits>
#include <cfloat>

using namespace std;

Factory::Factory()
{

}

IOperand* Factory::createInt8(const std::string& value)
{
	long long r = std::stoll(value);

	if ( r < -128 || r > 127) {
		throw Exceptions("overflow or underflow exceptions");
	} else {
		return new Operand(Int8, 0, value);
	}
}

IOperand* Factory::createInt16( std::string const &value)
{
	long long r = std::stoll(value);

	if (r < -32768 || r > 32767) {
		throw Exceptions("overflow or underflow exception");
	} else {
		return new Operand(Int16, 0, value);
	}
}

IOperand* Factory::createInt32(std::string const &value)
{
	long long r = std::stoll(value);

	if (r < -2147483648  || r > 2147483647) {
		throw Exceptions("overflow or underflow exception");
	} else {
		return new Operand(Int32, 0, value);
	}
}

IOperand* Factory::createFloat(std::string const &value)
{
	long long r = std::stoll(value);
	if (r < -FLT_MAX || r > FLT_MAX) {
		throw Exceptions("overflow or underflow exception");
	} else {
		return new Operand(Float, Operand::precisionFloat(), value);
	}
}

IOperand* Factory::createDouble(std::string const &value)
{
	long double r = std::stold(value);

	if (r > DBL_MAX || r < -DBL_MAX) {
		throw Exceptions("overflow or underflow exception");
	} else {
		return new Operand(Double, Operand::precisionDouble(), value);
	}
}

IOperand* Factory::createBigDecimal(std::string const &value)
{
	long double r = std::stold(value);
	if (r < std::numeric_limits<long double>::min() || r > std::numeric_limits<long double>::max()) {
		throw Exceptions("overflow or underflow exception");
	} else {
		return new Operand(BigDecimal, Operand::precisionBigDecimal(), value);
	}
}


IOperand* Factory::createOperand(eOperandType type , const std::string& value)
{
	Factory factory = Factory();
	switch (type) {
		case Int8:
		    return (factory.createInt8(value));
		case Int16:
				return (factory.createInt16(value));
		case Int32:
				return (factory.createInt32(value));
		case Float:
				return (factory.createFloat(value));
		case Double:
				return (factory.createDouble(value));
		case BigDecimal:
				return (factory.createBigDecimal(value));
		default:
				throw Exceptions("Invalid operand type");
	}
}
