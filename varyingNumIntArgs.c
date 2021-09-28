#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double average(int n,...) {
   va_list vlist;
   if(n<=0) return NAN;
   double sum = 0.0;
   va_start(vlist, n);
   for (int i = 0; i < n; i++)
     sum += va_arg(vlist, int);
   va_end(vlist);	
   return sum/n;
}

int main(void) {
  printf("Average of 1,2,3,4 = %f\n", average(4, 1,2,3,4));
  printf("Average of 10,20,30,40,50,60,70,80 = %f\n", average(8, 10,20,30,40,50,60,70,80));
  printf("Calling average with no 0 args =  %f\n",average(0)); 
}
