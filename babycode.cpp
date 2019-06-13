
#include "babycode.h"

using namespace std;

void machine::initialise(){

char mem[32];
for(int i = 0; i<32;i++)
    mem[i] = '0';
for(int i = 0; i < 32; i++){
    this->memory[i] = mem;
}
//this->acc = mem;


}

void machine::printmem(){
    for(int i = 0; i<32; i++){
    cout << this->memory[i];
    cout << endl;
    }
    cout << endl;

}

int machine::binToDec(int n)
{ 
    int num = n; 
    int dec_value = 0; 
  
    int base = 1; 
  
    int temp = num; 
    while (temp) { 
        int last_digit = temp % 10; 
        temp = temp / 10; 
  
        dec_value += last_digit * base; 
  
        base = base * 2; 
    } 
  
    return dec_value; 
} 

int machine::stringToInt(string s){

    int num = stoi(s);

    return num;

}

string machine::reverseString(string s){

    reverse(s.begin(), s.end());
    return s;

}

string machine::dectoBin(int n)
{
    string r;
    while(n!=0) {
        r=(n%2==0 ?"0":"1")+r; n/=2;
    }
}

void machine::loadProgram(){
    short count = 0;
    string line;
    ifstream infile("code.txt");
    if(infile.is_open()){
        while(!infile.eof()){

            getline(infile, line);
            this->memory[count] = line;
            count++;

        }
    infile.close();
    }else{
        cout << "Doki Doki can't open file" << endl;
    }
}

void machine::jmp(){

    this->line = this->binToDec(this->stringToInt(this->reverseString(this->operand)));

}

void machine::jrp(){
    line = this->binToDec(this->stringToInt(this->reverseString(this->operand))) + line;
}

void machine::ldn(){
    acc = -this->binToDec(this->stringToInt(this->reverseString(this->operand)));
}

void machine::sto(){
    memory[line].replace(0, 12, reverseString(dectoBin(acc)));
}

void machine::sub(){

}

void machine::cmp(){

}

void machine::stp(){

}

void machine::fetch(){

    this->operand = this->memory[this->line].substr(0,12);
    this->opcode = this->memory[this->line].substr(13, 3);
    //cout << this->opcode << " " << this->binToDec((this->stringToInt(this->reverseString(this->operand)))) << endl;

}

void machine::decode(){

if(this->opcode == "000"){
    this->jmp();
}
if(this->opcode == "100"){
    this->jrp();
}
if(this->opcode == "010"){
    this->ldn();
}
if(this->opcode == "110"){
    this->sto();
}
if(this->opcode == "001" || this->opcode == "101"){
    this->sub();
}
if(this->opcode == "011"){
    this->cmp();
}
if(this->opcode == "111"){
    this->stp();
}

}

void machine::execute(){



    this->line+=1;

}