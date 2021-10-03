#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "ntuple.h"


int main(void) {
  ntuple t = newTuple(1, "print please");
  printf("%s\n", ntupToString(t));
  //put(15 , "O", t);
  /*
  ntuple t = newTuple(1, "hello");
  printf("%s", stringy(t));
  return 0;
 */

}

#ifdef DEBUG
  int n = t -> arity;
  char *c = malloc(50 * sizeof(char*));
  strcat(c, "(");
  for(int i = 0; i < n; i++){
    strcat(c, "\"");
    strcat(c, t -> items[i]);
    if(i == n - 1){
      strcat(c, "\"");
    }
    else{
      strcat(c, "\",");
    }
  }
  strcat(c, ") \n");
  return c; 
  #endif