#include <stdlib.h>
#include "simpleCSVsorter.h"
#include "mergesort.c"

int main(int argc, char* argv[]){
  readfile();
  merge();
  print();
  return 0;
}
