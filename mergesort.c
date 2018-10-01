#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "simpleCSVsorter.h"

  
  // sorts LL by changing next pointers, not data. //
  
void MergeSort (Node** headRef){
    Node* head = *headRef;
    Node* a;
    Node* b;
    
    // B.C. > length 0 or 1 //
    if((head == NULL) || (head->next == NULL)){
      return;
    }
  // split head into 'a' 'b'//
    FrontBackSplit(head, &a, &b);
    
   // Recursive sort sublist//
    MergeSort(&a);
    MergeSort(&b);
    
   // answer = merg the 2 sorted lists together//
    *headRef = SortedMerge(a, b);
}
    
Node* SortedMerge(struct Node* a, struct Node* b){ 
  Node* result = NULL; 
  
/* Base cases */
  if (a == NULL) 
    return(b); 
  else if (b == NULL) 
    return(a);
      
      // choose between a or b, than recur //
  result = strcmp(a, b);
 
  if(result <=0){
   return(a);
  }else{
   return(b);
  }
}
      
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef){
      Node* fast;
      Node* slow;
      slow = source;
      fast = source->next;
      
      // keep going woith 'fast' and 'slow' nodes, each one node //
      
      while(fast != NULL)
      {
        fast = fast->next;
        if(fast != NULL)
        {
          slow = slow->next;
          fast = fast->next;
        }
      }
      // slow is tye midpoint area so split there //
      *frontRef = source;
      *backRef = slow->next;
      slow->next = NULL;
    }
      // print nodes in a LL //
      

     // insert a node in the beginning of a LL //
  }
}


