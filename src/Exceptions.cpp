/*
** EPITECH PROJECT, 2018
** CPP_abstractvm_2018
** File description:
** Core Process script
*/

#include "Exceptions.hpp"

Exceptions::Exceptions(string const &msg = "An error occurred") throw()
{
    err_msg = msg;
}

const char* Exceptions::what() const throw()
{
    return err_msg.c_str();
}

Exceptions::~Exceptions() {}
