# Processor-Simulator
Design and implement a simple processor simulator that mimics the basic functionalities of a processor. The simulator will execute instructions from a predefined instruction set architecture (ISA) and operate on a simulated memory system.

## How-To-Use
Compile and run the 'main.cpp' file. Change the text in the 'source.txt' to test out other instructions.

## Instruction Sets
For the following opcodes: `<OPERATION> <REGISTER> <VALUE>`
    <br> `ASG` Assign Value :  Transfer data from memory into a register 
    <br> `STR` Store Value : Transfer data from a register into memory
    <br> `ADD` Addition of Values
    <br> `SUB` Subtraction of Values <br> <br>
For the following opcodes: `<OPERATION> <ADDRESS>`
    <br> `JMP` Branching of Memory
    <br> `PRT` Printing of Memory <br> <br>
For the following opcodes: `<OPERATION>`
    <br> `EXT` Exit <br>

## Registers
<br> `R0` Register 0
<br> `R1` Register 1
<br> `R2` Register 2
<br> `R3` Register 3
<br> `R4` Register 4
<br> `R5` Register 5
<br> `R6` Register 6
<br> `R7` Register 7 

## Constraints: 
- Only allow jump forwards
- Only up to 4 registers
