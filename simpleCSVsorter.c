#include <stdlib.h>
#include "simpleCSVsorter.h"
#include "mergesort.c"

int main(int argc, char* argv[]){
  readfile();
  mergesort();
  print();
  return 0;
}


