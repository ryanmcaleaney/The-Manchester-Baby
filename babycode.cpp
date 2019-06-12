#include <iostream>
#include <fstream>
#include <vector>
#include "babycode.h"

using namespace std;

void machine::initialise(){

    for(int i = 0; i<32; i++){
        for(int j = 0; j<32; j++){
            this->memory[i][j] = '0';
        }

    }

}

void machine::printmem(){

    for(int i = 0; i<32; i++){
        for(int j = 0; j<32; j++){
            cout << this->memory[i][j];
        }
        cout << endl;
    }

}
