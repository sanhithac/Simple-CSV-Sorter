#include <stdio.h>
#include <stdlib.h>
#include <meregsort.h>

struct Node{   // to store a linked list in the data structure
  int data;
  struct Node* next;
}


        // mergesort for numric and dateTime
int a = numeric->data;
int b = dateTime->data;

String Node* mergesort( struct Node* a, struct Node* b){
  if(a == Null){
    return b;
  }else{
    if(b == Null){
      return a;
    }
    struct Nude* result = NUll;
    if( a->data <= b->data){
      result = a;
      result->next = mergesort(a->next, b);
    }else{
      result = b;
      result->next = mergesort(b->next, a);
    }
    return result;
  }
  // mergesort implemented without split
  
  String Node* mergeSPlit(){
    return 0;
  }
// testing mergesort not implementing string, numeric, dateTime yet

  

