#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

#ifndef BABYCODE.H
#define BABYCODE.H

class machine{
    public:
        void initialise();
        void clearmem();
        void loadProgram();
        void printmem();
        int binToDec(int n);
        int stringToInt(std::string s);
        std::string dectoBin(int n);
        std::string reverseString(std::string s);
        void fetch();
        void decode();
        void execute();
        void jmp();
        void jrp();
        void ldn();
        void sto();
        void sub();
        void cmp();
        void stp();
    
        string memory[32];
private:
        int acc;
        std::string opcode;
        std::string operand;
        int line = 2;

};

#endif