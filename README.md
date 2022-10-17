Part 1: llpivot- This is a recursive function that splits a linked list based on a pivot
Part 2: llfilter- This is a recursive function that filters elements in a linked list 
Part 3: stack- This is a templated Stack class based on vectors

To compile llrec-test:
make

To run llrec-test:
./llrec-test llrec-test1.in

To compile stack-test:
g++ -g -Wall -std=c++11 -c stack.h stack-test.cpp
g++ -g -Wall -std=c++11 -o stack-test stack-test.o

To run stack-test:
./stack-test

Part 4: Heap- This is an implementation of a heap using vectors
Part 5: Log Simulation- This is a logic simulator program (and, or, not) that uses my heap

To compile and run heap:
cd heap_test
make
make test

Valgrind:
make Valgrind

To compile and run the logic simulator (I am using AND as an example):
cd logicsim
./logicsim single_and.txt > my_and.uml
java -jar plantuml.jar my_and.uml