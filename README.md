# push_swap

## Table of Contents
+ [About](#about)
+ [Getting Started](#getting_started)
+ [Usage](#usage)

## About

This project sorts data on a stack, with a limited set of instructions, using
the lowest possible number of actions by manipulating various types of algorithms and choosing the most appropriate solution for an optimized data sorting.

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

This project works only on Linux/MacOS platforms only.

### Installing
To compile the program, you'll have to use your terminal and use the Makefile rules below:

 + ``make`` Generates _push_swap_ and an object file for each .c
 + ``make clean``  Deletes all object files
 + ``make fclean``  Deletes the object files and the _push_swap_
 + ``make re``  makes ``fclean`` and ``make`` again 

## Usage
After compiling the program type the executable file and the commands you'd like to try them on.
```
./push_swap <numbers>
```
the program will sort the numbers and place them all in one stack, it will write down the optimal consequence of commands needed to sort the stack.
