#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <arpa/inet.h>

#ifndef BABYCODE.H
#define BABYCODE.H

class machine{
    public:
        machine();
        ~machine();
        void initialise();
        void clearmem();
        void loadProgram();
        void printmem();
        int binToDec(int n);
        int stringToInt(std::string s);
        std::string dectoBin(int n);
        //std::string reverseString(std::string s);
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
private:
        bool stop = false;
        std::string memory[32];
        int acc = 0;
        std::string opcode;
        std::string operand;
        int line = 0;

};

#endif