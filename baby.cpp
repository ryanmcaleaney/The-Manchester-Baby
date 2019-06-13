#include "babycode.h"

using namespace std;

int main(){

    machine m;
    m.initialise();
    m.printmem();
    m.loadProgram();
    m.printmem();
    m.fetch();
    m.ldn();
    m.sto();
    cout << "Memory: " << m.memory[2];
}