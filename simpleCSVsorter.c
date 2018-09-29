#include <stdlib.h>
#include "simpleCSVsorter.h"
#include "mergesort.c"
#include <string.h>

int main(int argc, char* argv[]){
  if(argc<3){//error message if all the arguments are not available
    printf("Invalid Input");
    return 0;
  }
  Node *head=readfile(argv[2]);//read file and organize rows into nodes
  if(head==NULL)
     return 0;
  SortedMerge();//sorts the nodes/rows
  print(Node *head);//prints the sorted nodes to stdout
  return 0;
}

Node readfile(char *col[]){
  FILE *fp;
  char firstrow[600];
  fscanf(fp, "%[^\n]", firstrow);
  int colInd=columnNum(firstrow, col[]);
  if(colInd==-1){
    printf("Invalid Input");
    return NULL;
  while(
  
int columnNum(char *row, char *col){
  char *word;
  const char s[2]=",";
  char *token;
  int count=-1;
  token=strtok(row, s);
  token=remove_leading_spaces(token);
  while(token!=NULL){
    if(strcmp(token, col)==0){
      count++;
      return count;
    }
    count++;
    token=strtok(NULL, s);
  }
  return count;
}
  
char *remove_leading_spaces(char* line) 
{   
  char *trim(char* str){
  char *end;
  while(isspace((unsigned char)*str)){
	  str++;
  }
  end=str+strlen(str)-1;
  while(end>str && isspace((unsigned char)*end)){
	  end--;
  }
      return str;
} 

void print(Node *head){
  temp = head;
  while (Node->data != NULL){
    printf("Data = &d\n", temp->data);
    temp = temp->next;
  }
  return;
}
