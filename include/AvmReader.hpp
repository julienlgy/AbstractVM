/*
** EPITECH PROJECT, 2018
** CPP_abstractvm_2018
** File description:
** Exception Header
*/

#ifndef CPP_ABSTRACTVM_2019_AVMREADER_HPP
#define CPP_ABSTRACTVM_2019_AVMREADER_HPP

#include <string.h>

#include "AvmInstructions.hpp"

class AvmReader {
    public:
        AvmReader();
        bool loadFromFile(std::string file_url);
        bool loadFromInput();
        ~AvmReader();
    private:
        void storeInstruction(AvmInstructions* instruction);
        std::string reg_valid_command;
        AvmInstructions *getInstructionFromLine(std::string line);
};


#endif //CPP_ABSTRACTVM_2019_AVMREADER_HPP
