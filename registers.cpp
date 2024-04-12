#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Register{
private:
    const int REGISTER_SIZE; // Size of the registers in bytes
    vector<int> data; // Vector of int to store regsiter contents

public:
    Register(int size) : REGISTER_SIZE(size){
        data.resize(size, 0); // Each register slot contains a 0 value
    }

    int readByte(int address) const{
        if (address < 0 || address >= REGISTER_SIZE){
            cerr << "Error: Invalid register 1" << endl;
            return 0;
        }
        return data[address];
    }

    void writeByte(int address, const int& value){
        if(address < 0 || address >= REGISTER_SIZE){
            cerr << "Error: Invalid register 2" << endl;
            return;
        }
        data[address] = value;
    }

    void printRegisterContents(int startAddress, int endAddress) const{
        if(startAddress < 0 || startAddress >= REGISTER_SIZE || endAddress < 0 || endAddress >= REGISTER_SIZE || startAddress > endAddress){
            cerr << "Error: Invalid register 3" << endl;
            return;
        }

        cout << "Register Content:" << endl;
        for(int i = startAddress; i <= endAddress; ++i){
            cout << "Register " << i << ": " << data[i] << endl;
        }
    }

    const vector<int>& getDataVector() const{
        return data;
    }
};
