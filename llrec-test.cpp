#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------
bool isOdd(int x){ 
    if(x % 2 == 1){
        return true;
    }
    return false;
}

bool isEven(int x){
    if(x % 2 == 0){
        return true;
    }
    return false;
}

bool greaterThan10(int x){
    if(x > 10){
        return true;
    }
    return false;
}




int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
 //   Node* head = NULL;
    cout << "Original list: ";
    print(head);

    // Test out your linked list code

	cout << "Testing part 1" <<endl;
    //To test Part 1
    Node* s;
    Node* l;
    int pivot = 1;
    llpivot(head, s, l, pivot);
		cout << "Smaller than: " << endl;
    print(s);
		cout <<"Larger than: " << endl;
    print(l);
		cout <<"Head: " << endl;
    print(head);
    

	cout << "Testing Part 2" << endl;
  //To test Part 2
    Node* copy = readList(argv[1]);
    cout << "Original list: ";
    print(copy);
//    Node* tester = llfilter(copy, isOdd);
	Node* tester = llfilter(copy, greaterThan10);
//    cout << "Test: isOdd" << endl;
		cout << "Test: greaterThan10" << endl;
    print(tester);

    dealloc(copy);
    dealloc(s);
    dealloc(l);
    dealloc(tester);
    dealloc(head);

    return 0;

}
