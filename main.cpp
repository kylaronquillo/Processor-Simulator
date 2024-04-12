#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <map>
#include "memory.cpp"
#include "registers.cpp"
using namespace std;

// Define opcode mapping
map<string, string> opcodeMap = {
    {"ASG", "01"}, // assign value :  transfer data from memory into a register 
    {"STR", "02"}, // store value : transfer data from a register into memory
    {"ADD", "03"}, // add values
    {"SUB", "04"}, // subtract values
    {"JMP", "05"}, // jump address
    {"PRT", "06"} // print
};

// Define register mapping
map<string, string> registerMap = {
    {"R0", "00"},
    {"R1", "01"},
    {"R2", "02"},
    {"R3", "03"}
};

struct Instruction {
    string opcode; 
    string operand1;
    string operand2;
};

// Function to parse an instruction line
string parseInstruction(const string& line) {
    Instruction ins;
    string binary;
    ins.opcode = opcodeMap[line.substr(0, 3)]; // ASG (0, 1 ,2)
    if(ins.opcode == "01" || ins.opcode == "02" || ins.opcode == "03" || ins.opcode == "04"){
        ins.operand1 = registerMap[line.substr(4, 2)]; //R1 (4, 5)
        ins.operand2 = line.substr(7);
        binary = ins.opcode + ins.operand1 + ins.operand2;
    }
    else{
        ins.operand1 = line.substr(4);
        binary = ins.opcode + ins.operand1;
    }
    return binary;
}

string readInstruction(const string& line){
    string instruc = line.substr(0, 2);
    return instruc;
}

string readRegister(const string& line){
    string regis = line.substr(2, 2);
    return regis;
}

int getValue(const string& line){
    int x = stoi(line.substr(4));
    return x;
}

// class CPU{
// private:

// public:

//     void asg(const string& reg, int value){
//         registerMap[reg] = value;
//     }
//     void str(const string& reg, int value){
//         registerMap[reg] = value;
//     }
//     void add(const string& reg1, const string& reg2, const string& dest){
//         registerMap[dest] = registerMap[reg1] - registerMap[reg2];
//     }
//     void jump(int address) {
//         int pc = address;
//     }
    

// };

int main(){
    int pc = 0;
    //int numIns = 0;
    string line;

    // Initialize memory
    const int MEMORY_SIZE_BYTES = 64 * 1024; // 64KB memory size
    Memory memory(MEMORY_SIZE_BYTES);

    // Initialize registers
    
    //string arr_registers[REGISTER_SIZE];

    const int REGISTER_SIZE = 4;
    Register reg(REGISTER_SIZE);

    // Open the file containing instructions
    ifstream infile("source.txt");
    if (!infile) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    // Read each instruction from the file and write it to memory
    int address = 0;
    while (getline(infile, line)) {
        string instruc = parseInstruction(line);
        memory.writeByte(address++, instruc);
    }
    infile.close();

    

    cout << endl;
    // Access the data vector
    const vector<string>& memoryData = memory.getDataVector();

    // Perform operations based on instructions
    for (int i = 0; i < memoryData.size(); ++i){
        if(readInstruction(memoryData[i]) == "01"){
            int registerIndex = stoi(readRegister(memoryData[i]));
            reg.writeByte(registerIndex, getValue(memoryData[i]));
        }
        if(readInstruction(memoryData[i]) == "02"){
            int registerIndex = stoi(readRegister(memoryData[i]));
            string value = to_string(reg.readByte(registerIndex));
            memory.writeByte(getValue(memoryData[i]), value);
        }
        if(readInstruction(memoryData[i]) == "03"){
            int registerIndex = stoi(readRegister(memoryData[i]));
            int sum = getValue(memoryData[i]) + reg.readByte(registerIndex);
            reg.writeByte(registerIndex, sum);
        }
        if(readInstruction(memoryData[i]) == "04"){
            int registerIndex = stoi(readRegister(memoryData[i]));
            int diff = getValue(memoryData[i]) - reg.readByte(registerIndex);
            reg.writeByte(registerIndex, diff);
        }
        if(readInstruction(memoryData[i]) == "05"){

        }
    }
    memory.printMemoryContents(0,10); // Print the contents of memory
    reg.printRegisterContents(0,3);

    return 0;
}
