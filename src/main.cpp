/*
** EPITECH PROJECT, 2019
** AbstractVM
** File description:
**
*/

#include <iostream>
#include <string>
#include "Stack.hpp"
#include "AvmReader.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"
#include "CoreProcess.hpp"
#include "Exceptions.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Stack *exStack = Stack::getStack();
    AvmReader *reader = new AvmReader();
    try {
        if (argc == 2) {
            reader->loadFromFile(argv[1]);
        } else {
            reader->loadFromInput();
        }
        CoreProcess::readMemory();
    }
    catch (exception const& e) {
        cerr << "ERROR: " << e.what() << endl;
        exit(94);
    }

    delete reader;
    delete exStack;
}
