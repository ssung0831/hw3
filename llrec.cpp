#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void helper(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  if(head == NULL){
    if(smaller != NULL){
      smaller -> next = NULL;
    }
    
    if(larger != NULL){
      larger-> next = NULL;
    }
    return;
  }
  else if((head -> val) > pivot){ //larger
    if(larger == NULL){
      larger = head;
      Node* temp = head -> next;
      head = NULL;
			helper(temp, smaller, larger, pivot);
    }
    else{
      larger -> next = head;
      Node* temp = head -> next;
      head = NULL;
			helper(temp, smaller, larger -> next, pivot);
    }
  }
  else if((head -> val) <= pivot){ //smaller
    if(smaller == NULL){
      smaller = head;
      Node* temp = head -> next;
      head = NULL;
      helper(temp, smaller, larger, pivot);
    }
		else{
			smaller -> next = head;
      Node* temp = head -> next;
      head = NULL;
    	helper(temp, smaller -> next, larger, pivot);
		}
	}
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	smaller = NULL;
	larger = NULL;
	helper(head, smaller, larger, pivot);
}
