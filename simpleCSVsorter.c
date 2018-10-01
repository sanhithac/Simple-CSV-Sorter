#include <stdlib.h>
#include "simpleCSVsorter.h"
#include "mergesort.c"
#include <string.h>

int main(int argc, char* argv[]){
  //error message if all the arguments are not available
 if(argc<3){//error message if all the arguments are not available
    printf("Invalid Input\n");
    return 0;
  }
  FILE *fp;
  char firstrow[1000];
  fp=stdin;
   if(fp==NULL){
     printf("Invalid Input");
     return -1;
  }
  fscanf(fp, "%[^\n]", firstrow);
  int colInd=columnNum(firstrow, argv[2]);
  if(colInd==-1){
    printf("Invalid Input");
    return -1;
  }
	
  Node *head=readfile(colInd, fp);//read file and organize rows into nodes
	
  //error checking
  if(head==NULL)
     return 0;
	
  //sorts the nodes/rows
  Node **new= head;
  mergesort(head);
	
  //prints the first row and sorted nodes to stdout
  printf("%s\n", firstrow);
  print(head);
  return 0;
}


Node* readfile(int colInd, FILE *fp){
  char line[1000];
	
  //organizing the rows into nodes
  Node *temp =NULL;
  Node *head=NULL;
  Node *p=NULL;
  int size=0;
	
  while(fgets(line, 1000, fp)!=NULL){
    temp=(Node *)malloc(sizeof(Node));
    (temp)->row=line; 
    (temp)->data=tokenizer(colInd, line);
    if(head==NULL){
      head=temp;
    }
    else{
      p=head;
      while(p->next!=NULL){
	p=p->next;
      }
      p->next=temp;
    }
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
  while(token!=NULL){
  token=remove_leading_spaces(token);
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
  while(token!=NULL){
  token=remove_leading_spaces(token);
    if(col==count){
      return token;
    }
    count++;
    token=strtok(NULL,s);
  }
  return token;
}

	
//traverses through ll and prints nodes
void print(Node *head){
  Node *p=NULL;
  p=head;
  while (p!= NULL){
    printf("%s\n",p->row);
    p = p->next;
  }
  return;
}
