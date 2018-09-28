#include<stdio.h>
#include<stdlib.h>

struct Node{   // to store a linked list in the data structure
  int data;
  struct Node* next;
}
 // function prototypes //
struct Node* mergeSort( struct Node* a, struct Node* b){
  void FrontBackSplit (struct Node* source, struct Node** frontRef, struct Node** backRef);
  // sorts LL by changing next pointers, not data. //
  
  void sortedMerge (struct Node** headRef){
    struct Node * head = *headRef;
    struct Node* a;
    struct Node* b;
    
    // B.C. > length 0 or 1 //
    if((head == NULL) || (head->next == NULL)){
      return;
    }
  // split head into 'a' 'b'//
    FrontBackSplit(head, &a, &b);
    
   // Recursive sort sublist//
    sortedMerge(&a);
    SortedMerge(&b);
    
   // answer = merg the 2 sorted lists together//
    *headRef = mergeSort(a, b);
    
    struct Node* mergeSort(struct Node* a, struct Node* b)(
      struct Node* result = Null;
      
      //Best case//
      
      if(a ==N ULL)
      return(b);
      else if(b == Null)
      return(b);
      
      // choose between a or b, than recur //
      if(a->data <= b->data){
        result = a;
        result->next = mergeSort(a->next, b);
      }else{
        result b;
        result->next = mergeSort(a, b->next);
      }
      return(result);
     }
      
    void FrontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef){
      struct Node* fast;
      struct Node* slow;
      slow = source;
      fast = source->next;
      
      // keep going woith 'fast' and 'slow' nodes, each one node //
      
      while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
          slow = slow->next;
          fast = fast->next;
        }
      }
      // slow is tye midpoint area so split there //
      *frontRef = source;
      backRef = slow->next;
      slow->next = NULL;
    }
      // print nodes in a LL //
      
      void listPrint(struct Node *node){
        while(node != NULL){
          printf("%d", node->data);
          node = node->next;
        }
      }
     // insert a node in the beginning of a LL //
      void push(struct Node** head_ref, int new_data){
        // allocate node //
        struct Node* new node = (strcut Node*) malloc(sizeof(struct Node));
        
        // put in data //
        new_node->data = new_data;
        
        // linking old list with new node //
        new_node->next = (*head_ref);
        
        // move head to point to the new node //
        (*head_ref) = new_node;
      }
    
