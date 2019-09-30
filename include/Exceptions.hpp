/*
** EPITECH PROJECT, 2018
** CPP_abstractvm_2018
** File description:
** Exception Header
*/

#ifndef CPP_ABSTRACTVM_2019_EXCEPTIONS_HPP
#define CPP_ABSTRACTVM_2019_EXCEPTIONS_HPP

#include <string>
#include <exception>

using namespace std;

class Exceptions: public exception
{
    public:
        Exceptions(string const &msg) throw();
        virtual ~Exceptions() throw();
        virtual const char *what() const throw();

    private:
        string err_msg;
};

#endif //CPP_ABSTRACTVM_2019_EXCEPTIONS_HPP
