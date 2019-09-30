//
// Created by julien on 11/01/19.
//

#include "AvmReader.hpp"
#include "Stack.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

AvmReader::AvmReader()
{

}

AvmReader::~AvmReader()
{

}

bool AvmReader::loadFromFile(std::string file_url)
{
    // READ FILE HERE PER LINE.
    ifstream file(file_url.c_str());
    int i = 1;

    if (file) {
        string line;
        while (getline(file, line)) {
            if (line.size() == 0) { i++; continue; }
            if (line[0] == ';') { i++; continue; }
            AvmInstructions *line_instruction = getInstructionFromLine(line);
            if (line_instruction->getInstruction() == WRONG_COMMAND) {
                stringstream msg_err;
                msg_err << "Line " << i << ": Command not found";
                string err = msg_err.str();
                throw Exceptions(err);
            }
            storeInstruction(line_instruction);
            i++;
        }
        return (true);
    }
    throw Exceptions("can't read file");
}

bool AvmReader::loadFromInput()
{
    // READ FILE HERE FROM INPUT, WHILE != "exit"
    string line;
    int i = 1;
    int error = 0;

    while (line != ";;") {
        getline(cin, line);
        AvmInstructions *line_instruction = getInstructionFromLine(line);
        //cout << line_instruction->getInstruction() << " Value : " << line_instruction->getValue() << endl;
        if (line[0] != ';') {
            if (line_instruction->getInstruction() == WRONG_COMMAND)
                error = i;
            else if (error == 0)
                i++;
            storeInstruction(line_instruction);
        }
    }
    if (error) {
        stringstream msg_err;
        msg_err << "Line " << i << ": Command not found";
        string err = msg_err.str();
        throw Exceptions(err);
    }
    return true;
}

AvmInstructions *AvmReader::getInstructionFromLine(std::string line)
{
    // delete comments
    line = line.substr(0, line.find(";"));
    int space = line.find(" ");
    string instruction;
    string value;
    AvmInstructions *result = new AvmInstructions();

    if (space != -1) {
        instruction = line.substr(0, space);
        value = line.substr(space + 1, line.size());
    } else {
        instruction = line;
        value = "NaN";
    }
    return new AvmInstructions(result->searchForInstruction(instruction), value);
}

void AvmReader::storeInstruction(AvmInstructions* instruction)
{
    (Stack::getStack()->instructions).push_back(instruction);
}
