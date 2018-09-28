#include <stdlib.h>
#include "simpleCSVsorter.h"
#include "mergesort.c"

int main(int argc, char* argv[]){
  if(argc<3){//error message if all the arguments are not available
    printf("Invalid Input");
    return 0;
  }
  readfile(argv[2]);//read file and organize rows into nodes
  SortedMerge();//sorts the nodes/rows
  print(Node *head);//prints the sorted nodes to stdout
  return 0;
}

Node readfile(char *col[]){
  FILE *fp;
  char firstrow[600];
  fscanf(fp, "%[^\n]", firstrow);
  columnNum(firstrow, col[]);
  while(
  
int columnNum(Char *row[], char *col[]){
  char word[60];
  const char s[2]=",";
  char *token;
  token=strtok(row, s);
  token=remove_leading_spaces(token);
  
  
static void remove_leading_spaces(char* line) 
{   
   int i; 
   for(i = 0; (*line)[i] == ' '; i++) {
    *line += i;
   }
} 
  
