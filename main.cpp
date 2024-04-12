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
    {"PRT", "06"}, // print
    {"EXT", "07"} // exit program
};

// Define register mapping
map<string, string> registerMap = {
    {"R0", "00"},
    {"R1", "01"},
    {"R2", "02"},
    {"R3", "03"},
    {"R4", "04"},
    {"R5", "05"},
    {"R6", "06"},
    {"R7", "07"}
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
    else if(ins.opcode == "05" || ins.opcode == "06"){
        ins.operand1 = line.substr(4);
        binary = ins.opcode + ins.operand1;
    }
    else{
        binary = ins.opcode;
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

int main(){
    int pc = 0;
    //int numIns = 0;
    string line;

    // Initialize memory
    const int MEMORY_SIZE_BYTES = 64 * 1024; // 64KB memory size
    Memory memory(MEMORY_SIZE_BYTES);

    // Initialize registers
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
    for (; pc < memoryData.size(); ++pc){
        if(readInstruction(memoryData[pc]) == "01"){
            int registerIndex = stoi(readRegister(memoryData[pc]));
            reg.writeByte(registerIndex, getValue(memoryData[pc]));
        }
        if(readInstruction(memoryData[pc]) == "02"){
            int registerIndex = stoi(readRegister(memoryData[pc]));
            string value = to_string(reg.readByte(registerIndex));
            memory.writeByte(getValue(memoryData[pc]), value);
        }
        if(readInstruction(memoryData[pc]) == "03"){
            int registerIndex = stoi(readRegister(memoryData[pc]));
            int sum = getValue(memoryData[pc]) + reg.readByte(registerIndex);
            reg.writeByte(registerIndex, sum);
        }
        if(readInstruction(memoryData[pc]) == "04"){
            int registerIndex = stoi(readRegister(memoryData[pc]));
            int diff = getValue(memoryData[pc]) - reg.readByte(registerIndex);
            reg.writeByte(registerIndex, diff);
        }
        if(readInstruction(memoryData[pc]) == "05"){
            int registerIndex = stoi(readRegister(memoryData[pc]));
            pc = registerIndex - 1;
        }
        if(readInstruction(memoryData[pc]) == "06"){
            int registerIndex = stoi(readRegister(memoryData[pc]));
            memory.printMemoryContents(registerIndex,registerIndex);
        }
        if(readInstruction(memoryData[pc]) == "07"){
            break;
        }
    }

    memory.printMemoryContents(0, memoryData.size()); // Print the contents of memory
    reg.printRegisterContents(0,7);

    return 0;
}
