
#include "babycode.h"

using namespace std;

machine::machine(){
    
}
machine::~machine(){

}

void machine::initialise(){

char mem[32];
for(int i = 0; i<32;i++)
    mem[i] = '0';
for(int i = 0; i < 32; i++){
    memory[i] = mem;
}
//acc = mem;


}

void machine::printmem(){
    for(int i = 0; i<32; i++){
    if(i < 10)
    cout << "0";
    cout << i << ": ";
    cout << memory[i];
    cout << endl;
    }
    cout << endl;

}



int machine::stringToInt(string bin){
//declare variables
	int dec = 0;
	int temp = 0;
	int base = 1;
	int binSize = bin.length();
	
	//convert binary to decimal
	for(int i = 0; i < binSize-1; i++){
		temp = bin[i] - '0';
		dec = dec + temp*base;
		base = base*2;
	}

	//determine if negative
	if(bin[binSize-1] == '1'){dec = -dec;}
	return dec;
}

int machine::binToDec(int n)
{ 
    int num = htonl(n); 
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

string machine::dectoBin(int dec)
{
    string bin = "";	//binary value
	int rem;			//remainder
	int binSize; 		//size of bin value 
	int decTemp = dec;	//temp decimal value


	//make decimal positive for calculation
	if(dec < 0){
		decTemp = -decTemp;
	}

	//loop until full binary number has been created
	while(decTemp != 0)
	{
		rem = decTemp%2;
		decTemp = decTemp/2;
		if(rem == 0){
			bin = bin + '0';
		}
		else{
			bin = bin + '1';
		}
	}

	binSize = bin.length();
	//fill in blank operand space
	if(binSize < 32-1){
		bin.append((32-1) - (binSize),'0');
	}
	//take into account twos compliment
	if(dec < 0){
		bin = bin + '1';
	}
	else{
		bin = bin + '0';
	}
	return bin;
}

void machine::loadProgram(){
    short count = 0;
    string line;
    ifstream infile("code.txt");
    if(infile.is_open()){
        while(!infile.eof()){

            getline(infile, line);
            memory[count] = line;
            count++;

        }
    infile.close();
    }else{
        cout << "Doki Doki can't open file" << endl;
    }
}

void machine::jmp(){

    line = binToDec(stringToInt((operand)));

}

void machine::jrp(){
    line = binToDec(stringToInt((operand))) + line;
}

void machine::ldn(){
    acc = -binToDec(stringToInt((operand)));
}

void machine::sto(){
    memory[line].replace(0, dectoBin(acc).length(), (dectoBin(acc)));
}

void machine::sub(){
    acc = acc - binToDec(stringToInt((operand)));
}

void machine::cmp(){
    if(acc < 0){
        line+=1;
    }
}

void machine::stp(){
    stop = true;
}

void machine::fetch(){

    operand = memory[line].substr(0,12);
    opcode = memory[line].substr(13, 3);
    //cout << opcode << " " << binToDec((stringToInt((operand)))) << endl;

}

void machine::decode(){

if(opcode == "000"){
    jmp();
}else
if(opcode == "100"){
    jrp();
}else
if(opcode == "010"){
    ldn();
}else
if(opcode == "110"){
    sto();
}else
if(opcode == "001" || opcode == "101"){
    sub();
}else
if(opcode == "011"){
    cmp();
}else
if(opcode == "111"){
    stp();
}

}

void machine::execute(){
    initialise();
    loadProgram();
    cout <<"\n"<<memory[8].substr(0, 12)<<"\n"<< endl;
    cout << "\nLine: "<< line << "\nAccumulator: " << acc << "\nopcode: " << opcode << "\noperand: " << operand << endl << endl; 
    int debug = 0;
    while(stop == false){
        fetch();
        decode();
        printmem();
        cout << "\nLine: "<< line+1 << "\nAccumulator: " << acc << "\nopcode: " << opcode << "\noperand: " << operand << endl << endl; 
        line+=1;
    }
}