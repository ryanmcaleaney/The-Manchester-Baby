#ifndef BABYCODE.H
#define BABYCODE.H

class machine{
    public:
        void initialise();
        void clearmem();
        void loadProgram();
        void printmem();
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
        char memory[32][32];
        int counter = 0;
        int acc[32];
        int opcode;
        int operand;
        int line;

};

#endif