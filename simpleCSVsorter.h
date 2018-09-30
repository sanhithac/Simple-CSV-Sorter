#include <stdlib.h>

typedef struct{
  void *data;
  char[] *row;
  Node *next;
}Node;

void readfile();
char *remove_leading_spaces(char* line);
int columnNum(char *row, char *col);
char *tokenizer(int col, char *line);
String Node* SortedMerge( struct Node* a, struct Node* b);
void print(struct Node* a);

