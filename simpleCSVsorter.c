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
  char *firstrow;
  fp=stdin;
  char line[1000];
  if(fp==NULL){
    printf("Invalid Input");
    return NULL;
  }
  fscanf(fp, "%[^\n]", firstrow);
  int colInd=columnNum(firstrow, col[]);
  if(colInd==-1){
    printf("Invalid Input");
    return NULL;
  }
  Node *curr =NULL;
  Node *head=NULL;
  Node *next=NULL;
  int size =0;
  while(fgets(line, 1000, fp)!=NULL){
    curr=(Node *)malloc(sizeof(Node));
    (curr)->row=line;
    printf("%s\n", (curr)->row);
    (curr)->ptr=next;
    curr=next;
    if(size==0)
	    head=curr;
    size++;
  }
  
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
  return -1;
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
	
char *tokenizer(int col, char *line){
  const char s[2]=",";
  char *token;
  int count=0;
  token=strtok(line, s);
  token=trim(token);
  while(token!=NULL){
    if(col==count)
      return token;
    count++;
    token=strtok(NULL,s);
  }
  return token;
}

void print(Node *head){
  temp = head;
  while (Node->ptr != NULL){
    printf("Data = &d\n", temp->data);
    temp = temp->next;
  }
  return;
}
