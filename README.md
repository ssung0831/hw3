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