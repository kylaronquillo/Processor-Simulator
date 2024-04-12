# Processor-Simulator
Design and implement a simple processor simulator that mimics the basic functionalities of a processor. The simulator will execute instructions from a predefined instruction set architecture (ISA) and operate on a simulated memory system.

## How-To-Use
Compile and run the 'main.cpp' file. Change the text in the 'source.txt' to test out other instructions.

## Instruction Sets
For the following opcodes: `<OPERATION> <REGISTER> <VALUE>`
    `ASG` <br> Assign Value :  Transfer data from memory into a register 
    `STR` <br> Store Value : Transfer data from a register into memory
    `ADD` <br> Addition of Values
    `SUB` <br> Subtraction of Values
For the following opcodes: `<OPERATION> <ADDRESS>`
    `JMP` <br> Branching of Memory
    `PRT` <br> Printing of Memory
For the following opcodes: `<OPERATION>`
    `EXT` <br> Exit 

## Registers
`R0` <br> Register 0
`R1` <br> Register 1
`R2` <br> Register 2
`R3` <br> Register 3
`R4` <br> Register 4
`R5` <br> Register 5
`R6` <br> Register 6
`R7` <br> Register 7 

## Constraints: 
Only allow jump forwards
Only up to 4 registers
