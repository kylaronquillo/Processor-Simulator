#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Memory {
private:
    const int MEMORY_SIZE; // Size of the memory in bytes
    vector<string> data; // Vector of strings to store memory contents

public:
    Memory(int size) : MEMORY_SIZE(size) {
        data.resize(size, "\0\0"); // Each memory slot contains a null string
    }

    // Read a byte from memory at the given address
    string readByte(int address) const {
        if (address < 0 || address >= MEMORY_SIZE) {
            cerr << "Error: Invalid memory address" << endl;
            return ""; // Return empty string for invalid address
        }
        return data[address];
    }

    // Write a byte to memory at the given address
    void writeByte(int address, const string& value) {
        if (address < 0 || address >= MEMORY_SIZE) {
            cerr << "Error: Invalid memory address" << endl;
            return;
        }
        data[address] = value;
    }

    // Print the contents of the memory within a specified range
    void printMemoryContents(int startAddress, int endAddress) const {
        if (startAddress < 0 || startAddress >= MEMORY_SIZE || endAddress < 0 || endAddress > MEMORY_SIZE || startAddress > endAddress) {
            cerr << "Error: Invalid memory range" << endl;
            return;
        }

        cout << "Memory Contents:" << endl;
        for (int i = startAddress; i <= endAddress; ++i) {
            if(!data[i].empty())
                cout << "Address " << i << ": " << data[i] << endl;
        }
    }

    // Get a reference to the data vector
    const vector<string>& getDataVector() const {
        return data;
    }
};
