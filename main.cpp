#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <map>
#include "memory.cpp"
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
    ins.opcode = opcodeMap[line.substr(0, 3)]; // ASG (0, 1 ,2)
    ins.operand1 = registerMap[line.substr(4, 2)]; //R1 (4, 5)
    ins.operand2 = line.substr(7);
    string binary = ins.opcode + ins.operand1 + ins.operand2;
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
    const int REGISTER_SIZE = 4;
    string arr_registers[REGISTER_SIZE];

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

    memory.printMemoryContents(0,10); // Print the contents of memory

    cout << endl;
    // Access the data vector
    const vector<string>& memoryData = memory.getDataVector();

    // Perform operations based on instructions
    for (int i = 0; i < memoryData.size(); ++i){
        if(readInstruction(memoryData[i]) == "01")(
            //load function
            
        )
    }

    return 0;
}
