# 0x19. C - Stacks, Queues - LIFO, FIFO

**`About:`** In this project, we created a simple interpreter for Monty ByteCodes. The interpreter reads a bytecode file and executes the bytecode commands.

## The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

## Monty byte code files

A Monty Byte Code file is a binary file that stores a series of instructions in a compact and platform-independent format. These instructions are designed to be executed by a Monty virtual machine, allowing Monty programs to run efficiently and consistently across different systems.

## Compilation & Usage

* These codes were compiled using: `gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
* To run this project use: `./monty bytecodes/file_name.m`
