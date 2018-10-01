#include <stdlib.h>

typedef struct Node{
  char *data;
  char *row;
  struct Node *next;
}Node;

Node* readfile(int colInd, FILE *fp);
char *remove_leading_spaces(char* str);
int columnNum(char *row, char *col);
char *tokenizer(int col, char *line);
void FrontBackSplit (Node* source, Node** frontRef, Node** backRef);
void MergeSort (Node* headRef);
Node* SortedMerge( Node* a, Node* b);
void print( Node* a);
void Finish(Node* head);
