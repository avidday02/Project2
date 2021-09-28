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
