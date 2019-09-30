/*
** EPITECH PROJECT, 2018
** CPP_abstractvm_2018
** File description:
** Core Process script
*/

#include "CoreProcess.hpp"
#include "Exceptions.hpp"

IOperand* CoreProcess::registers[15] = {0};

void CoreProcess::readMemory()
{
    AvmInstructions* instruction;
    bool hasExited = false;

    while(Stack::getStack()->instructions.size() != 0) {
        instruction = Stack::getStack()->instructions.front();
        Stack::getStack()->instructions.pop_front();
        if (instruction->getInstruction() == EXIT) {
            hasExited = true;
            break;
        }
        executeCommand(instruction);
    }

    if (!hasExited)
        throw Exceptions("No exit");
}

bool CoreProcess::doPush(std::string instruction)
{
    std::string operand = instruction.substr(0, instruction.find("("));
    std::string value = instruction.substr(instruction.find("(") + 1);
    value = value.substr(0,value.find(")"));
    //value[value.find(")")] = '\0';
    //EXCEPTIONS// if value !=! nombre = Throw new exception
    Stack::getStack()->operands.push_front(
      Factory::createOperand(geteOperandType(operand), value)
    );
    return (true);
}

bool CoreProcess::doPop()
{
    if (!Stack::getStack()->operands.size())
        throw Exceptions("Can't drop on empty stack");
    Stack::getStack()->operands.pop_front();
    return (true);
}

bool CoreProcess::doClear()
{
    Stack::getStack()->operands.clear();
    return (true);
}

bool CoreProcess::doDup()
{
    if (!Stack::getStack()->operands.size())
        throw Exceptions("Can't duplicate on empty stack");
    IOperand *toCopy = Stack::getStack()->operands.front();
    IOperand *toPaste = Factory::createOperand(toCopy->getType(), toCopy->toString());
    Stack::getStack()->operands.push_front(toPaste);
    return (true);
}

bool CoreProcess::doSwap()
{
    if (Stack::getStack()->operands.size() < 2)
        throw Exceptions("Can't swap with less than 2 operands");
    IOperand *toCopy = Stack::getStack()->operands.front();
    IOperand *toSwap = Factory::createOperand(toCopy->getType(), toCopy->toString());
    Stack::getStack()->operands.pop_front();
    IOperand *toSwap_2 = Stack::getStack()->operands.front();
    Stack::getStack()->operands.pop_front();
    Stack::getStack()->operands.push_front(toSwap_2);
    Stack::getStack()->operands.push_front(toSwap);
    return (true);
}

bool CoreProcess::doDump()
{
    list<IOperand *> memory = Stack::getStack()->operands;

    for (std::list<IOperand *>::iterator it=memory.begin(); it != memory.end(); ++it)
        cout << (*it)->toString() << endl;

    return (true);
}

bool CoreProcess::doPrint()
{
    if (Stack::getStack()->operands.size() == 0)
        throw Exceptions("Can't do print on empty memory");
    IOperand *valueToDisplay = Stack::getStack()->operands.front();
    if (!valueToDisplay->getType() == Int8)
        throw Exceptions("The top value isn't a int8 type");
    cout << (char) stoi(valueToDisplay->toString()) << endl;
    return (true);
}

bool CoreProcess::doAssert(std::string instruction)
{
    IOperand *valueToCompare = Stack::getStack()->operands.front();
    doPush(instruction);
    IOperand *valueToCompare_2 = Stack::getStack()->operands.front();
    if (valueToCompare->getType() == valueToCompare_2->getType()) {
        string t = valueToCompare->toString();
        string tr = valueToCompare_2->toString();
        if (t.compare(tr) == 0) {
            Stack::getStack()->operands.pop_front();
            return (true);
        }
    }
    cout << valueToCompare->toString() << endl;
    cout << valueToCompare_2->toString() << endl;
    throw Exceptions("Assert failed");
}

bool CoreProcess::doLoad(std::string instruction)
{
    string operand = instruction.substr(0, instruction.find("("));
    string str_value = instruction.substr(instruction.find("(") + 1);
    str_value = str_value.substr(0,str_value.find(")"));
    int value = atoi(str_value.c_str());
    if (value < 0 || value > 15)
        throw Exceptions("There are only 16 registers (0-15)");
    if (CoreProcess::registers[value] == 0)
        throw Exceptions("Register cell is empty");
    Stack::getStack()->operands.push_front(registers[value]);
    return (true);
}

bool CoreProcess::doStore(std::string instruction)
{
    if (!Stack::getStack()->operands.size())
        throw Exceptions("Can't store with empty stack");
    string operand = instruction.substr(0, instruction.find("("));
    string str_value = instruction.substr(instruction.find("(") + 1);
    str_value = str_value.substr(0,str_value.find(")"));
    int value = atoi(str_value.c_str());
    if (value < 0 || value > 15)
        throw Exceptions("There are only 16 registers (0-15)");

    CoreProcess::registers[value] = Stack::getStack()->operands.front();
    CoreProcess::doPop();

    return (true);
}

/**
  * OPERAND FUNCTIONS
  */

bool CoreProcess::doOperand(instructionsName name)
{
    if (Stack::getStack()->operands.size() < 2)
        throw Exceptions("Can't operate with less than 2 operands");
    IOperand *toCopy = Stack::getStack()->operands.front();
    IOperand *valueToAdd = Factory::createOperand(toCopy->getType(), toCopy->toString());
    Stack::getStack()->operands.pop_front();
    IOperand *valueToAdd_2 = Stack::getStack()->operands.front();
    Stack::getStack()->operands.pop_front();
    IOperand *result;

    switch (name) {
        case ADD:
            result = *valueToAdd_2 + *valueToAdd;
            break;
        case SUB:
            result = *valueToAdd_2 - *valueToAdd;
            break;
        case MUL:
            result = *valueToAdd_2 * *valueToAdd;
            break;
        case DIV:
            result = *valueToAdd_2 / *valueToAdd;
            break;
        case MOD:
            result = *valueToAdd_2 % *valueToAdd;
            break;
        default:
            result = 0;
            throw Exceptions("Unknown instruction");
    }
    Stack::getStack()->operands.push_front(result);
    return (true);
}

/**
  * Private functionnal functions
  */
eOperandType CoreProcess::geteOperandType(const std::string type)
{
    if (type == "int8")
        return (Int8);
    else if (type == "int16")
        return (Int16);
    else if (type == "int32")
          return (Int32);
    else if (type == "float")
        return (Float);
    else if (type == "double")
        return (Double);
    else {
        if (type == "bigdecimal")
          return (BigDecimal);
    }

    throw Exceptions("Invalid type");
}

void CoreProcess::executeCommand(AvmInstructions * instruction)
{
    instructionsName in = instruction->getInstruction();

    if (in == ADD || in == SUB || in == MUL || in == MOD || in == DIV)
        doOperand(in);
    else {
        switch(in) {
            case PUSH:
                doPush(instruction->getValue());
                break;
            case POP:
                doPop();
                break;
            case CLEAR:
                doClear();
                break;
            case DUP:
                doDup();
                break;
            case SWAP:
                doSwap();
                break;
            case DUMP:
                doDump();
                break;
            case ASSERT:
                doAssert(instruction->getValue());
                break;
            case LOAD:
                doLoad(instruction->getValue());
                break;
            case STORE:
                doStore(instruction->getValue());
                break;
            case PRINT:
                doPrint();
                break;
            default:
                throw Exceptions("Ceci est impossible mdr");
        }
    }
}
