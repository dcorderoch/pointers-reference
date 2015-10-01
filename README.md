# pointers-reference
this repository contains a small demonstrattion of the use of pointers in C/C++ code

it's meant to be used as a reference to for example, check the syntax of dynamic allocation of arrays, matrixes or pointer arrays (which to C/C++ are more or less the same)

this program can be compiled with gcc like this:

gcc main.c -o pointers

it can be run like this:

./pointers

alternatively a Makefile is provided, so it can be compiled and run like this:

make run

it can be checked for memory leaks with valgrind like this:

valgrind --leak-check=full ./pointers

Valgrind is a flexible program for debugging and profiling Linux executables.
For more comprehensive information, please visit http://www.valgrind.org
