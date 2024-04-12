#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <map>
#include "Processor-Simulator/memory.cpp"
using namespace std;

// Define opcode mapping
map<string, string> opcodeMap = {
    {"ASG", "0000"},
    {"STR", "0001"},
    {"AAD", "0010"},
    {"SAD", "0011"},
    {"JAD", "0100"},
    {"PRT", "0101"}
};

// Define register mapping
map<string, string> registerMap = {
    {"R0", "0000"},
    {"R1", "0001"},
    {"R2", "0010"},
    {"R3", "0011"},
};

struct Instruction {
    string opcode; 
    string operand1;
    string operand2;
};

// Function to parse an instruction line
string parseInstruction(const string& line) {
    Instruction ins;
    // cout << line.substr(0, 3)<<endl;
    // cout << line.substr(4, 2)<<endl;
    // cout << line.substr(7)<<endl;
    ins.opcode = opcodeMap[line.substr(0, 3)]; // ASG (0, 1 ,2)
    ins.operand1 = registerMap[line.substr(4, 2)]; //R1 (4, 5)
    ins.operand2 = line.substr(7);
    string binary = ins.opcode + ins.operand1 + ins.operand2;
    return binary;
}

string readInstruction(const string& line){
    string instruc = line.substr(0, 4);
    return instruc;
}

string readInstruction(const string& line){
    string regis = line.substr(5, 4);
    return regis;
}

int getValue(const string& line){
    int x = stoi(line.substr(5, 4));
    return x;
}

string readRegister(const string& line){
    Instruction ins;
    ins.opcode = line.substr(5, 4);
    return ins.opcode;
}

int main(){
    int numIns = 0;
    string line;

    cout << "Number of Instructions: ";
    cin >> numIns;
    cin.ignore(); 

    // Input to file
    cout << "\nWrite to File (source.txt):\n";
    ofstream source("source.txt");
    for(int i = 0; i < numIns; i++){
        getline(cin, line);
        source << line << endl;
    }
    source.close();

    // Open the file containing instructions
    ifstream infile("source.txt");
    if (!infile) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    // Initialize memory
    const int MEMORY_SIZE_BYTES = 64 * 1024; // 64KB memory size
    Memory memory(MEMORY_SIZE_BYTES);

    // Initialize registers
    const int REGISTER_SIZE = 4;
    string arr_registers[REGISTER_SIZE];

    // Read each instruction from the file and write it to memory
    int address = 0;

    while (getline(infile, line)) {
        string instruc = parseInstruction(line);
        memory.writeByte(address++, instruc);
    }
    infile.close();

    memory.printMemoryContents(0,numIns); // Print the contents of memory

    cout << endl;
    // Access the data vector
    const vector<string>& memoryData = memory.getDataVector();


    // Perform operations based on instructions
    for (int i = 0; i < memoryData.size(); ++i){
        if(readInstruction(memoryData[i]) == "0000")(
            
        )
    }

    return 0;
}
