#include <stdlib.h>
#include "simpleCSVsorter.h"
#include "mergesort.c"
#include <string.h>

int main(int argc, char* argv[]){
  //error message if all the arguments are not available
  if(argc<3){
    printf("Invalid Input");
    return 0;
  }
	
  //opening the file and storing the values of the first row
  FILE *fp;
  char *firstrow;
  fp=stdin;
  char line[1000];
  if(fp==NULL){
    printf("Invalid Input");
    return NULL;
  }
  fscanf(fp, "%[^\n]", firstrow);

  //read file and organize rows into nodes
  Node *head=readfile(argv[2]);

  //error checking
  if(head==NULL)
     return 0;
	
  //sorts the nodes/rows	
  SortedMerge();
	
  //prints the first row and sorted nodes to stdout
  printf("%s\n", firstrow);
  print(Node *head);
  return 0;
}


//reads file and organizes rows into nodes
Node readfile(char *col[]){
  //finds the index of column passed in args
  int colInd=columnNum(firstrow, col[]);

  //error checking
  if(colInd==-1){
    printf("Invalid Input");
    return NULL;
  }
	
  //organizing the rows into nodes
  Node *curr =NULL;
  Node *head=NULL;
  Node *next=NULL;
  int size =0;
  while(fgets(line, 1000, fp)!=NULL){
    curr=(Node *)malloc(sizeof(Node));
    (curr)->row=line;
    (curr->data)=tokenizer(colInd, line);
    (curr)->next=next;
    curr=next;
    if(size==0)
	    head=curr;
    size++;
  }
  return head;
}
 

//finds the index of column
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
  

//removes the leading and trailing whitespaces of a token
char *remove_leading_spaces(char* str) 
{   
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
	
	
//splits row into col values
char *tokenizer(int col, char *line){
  const char s[2]=",";
  char *token;
  int count=0;
  token=strtok(line, s);
  token=remove_leading_spaces(token);
  while(token!=NULL){
    if(col==count)
      return token;
    count++;
    token=strtok(NULL,s);
  }
  return token;
}

	
//traverses through ll and prints nodes
void print(Node *head){
  temp = head;
  while (temp->next != NULL){
    printf(temp->row);
    temp = temp->next;
  }
  return;
}
