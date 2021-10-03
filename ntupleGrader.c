#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "ntuple.h"

char *sp(int n) {
  char *s = malloc(n+1); strcpy(s,"");
  for(int i = 1; i <= n; i++) strcat(s," ");
  return s;
}

int main(void) {
  int num = 0, wrong=0,n;
  char *buff,*s;
  bool err = false;

  ntuple n1,n2,n3,n4;
  
  printf("%2d) ",++num);
  n1 = newTuple(0);
  printf("%d%s%s",n1->arity,sp(11),"<-- 0 (newTuple) ");
#ifdef ALLFAIL
  err = true;
#else
  err = n1->arity != 0;
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);

  printf("%2d) ",++num);
  n1 = newTuple(3,"i0","i1","i2");
  printf("%d%s%s",n1->arity,sp(11),"<-- 3 (newTuple) ");
#ifdef ALLFAIL
  err = true;
#else
  err = n1->arity != 3;
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);

  printf("%2d) ",++num);  
  printf("%s%s%s",n1->items[1],sp(10),"<-- i1 (newTuple) ");
#ifdef ALLFAIL
  err = true;
#else
  err = strcmp(n1->items[1],"i1") != 0;
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);

  printf("%2d) ",++num);
  n2 = newTuple(50,
		"i0","i1","i2","i3","i4","i5","i6","i7","i8","i9",
		"i10","i11","i12","i13","i14","i15","i16","i17","i18","i19",
		"i20","i21","i22","i23","i24","i25","i26","i27","i28","i29",
		"i30","i31","i32","i33","i34","i35","i36","i37","38","i39",
		"i40","i41","i42","i43","i44","i45","i46","i47","i48","i49");
  printf("%s%s%s",n2->items[49],sp(9),"<-- i49 (newTuple) ");

#ifdef ALLFAIL
  err = true;
#else
  err = strcmp(n2->items[49],"i49") != 0;
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);

  printf("%2d) ",++num);
  printf("%d%s%s",n=arity(n2),sp(10),"<-- 50 (arity) ");
#ifdef ALLFAIL
  err = true;
#else
  err = n != 50;
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);

  printf("%2d) ",++num);
  printf("%s%s%s",(n=isNtuple(n1,3))?"true":"false",sp(8),"<-- true (isNtuple) ");
#ifdef ALLFAIL
  err = true;
#else
  err = (n == false);
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);

  printf("%2d) ",++num);  
  n3 = newTuple(3,"i0","i1","i2");
  printf("%s%s%s",(n=equal(n1,n3))?"true":"false",sp(8),"<-- true (equal) ");
#ifdef ALLFAIL
  err = true;
#else
  err = (n == false);
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);

  printf("%2d) ",++num);  
  n3 = newTuple(3,"i0","i1","i2");
  printf("%s%s%s",(n=equal(n1,n2))?"true":"false",sp(7),"<-- false (equal) ");
#ifdef ALLFAIL
  err = true;
#else
  err = (n != false);
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);

  printf("%2d) ",++num);  
  s = get(0,n1);
  printf("%s%s%s",s,sp(10),"<-- i0 (get) ");
#ifdef ALLFAIL
  err = true;
#else
  err = strcmp(s,"i0") != 0;
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);

    printf("%2d) ",++num);  
  s = get(23,n2);
  printf("%s%s%s",s,sp(9),"<-- i23 (get) ");
#ifdef ALLFAIL
  err = true;
#else
  err = strcmp(s,"i23") != 0;
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);


  printf("%2d) ",++num);  
  put(0,"x0",n3);
  printf("%s%s%s",s=n3->items[0],sp(10),"<-- x0 (put) ");
#ifdef ALLFAIL
  err = true;
#else
  err = strcmp(s,"x0") != 0;
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);

  printf("%2d) ",++num);  
  put(0,"x0",n2);
  printf("%s%s%s",s=n2->items[0],sp(10),"<-- x0 (put) ");
#ifdef ALLFAIL
  err = true;
#else
  err = strcmp(s,"x0") != 0;
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);
  
  printf("%2d) ",++num);
  put(0,"x48",n2);
  printf("%s%s%s",(s=n2->items[0]),sp(9),"<-- x48 (put) ");
#ifdef ALLFAIL
  err = true;
#else
  err = strcmp(s,"x48") != 0;
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);

  printf("%2d) ",++num);
  n4 = newTuple(0);
  printf("%s%s%s",s=ntupToString(n4),sp(10),"<-- () (ntupToString) ");
#ifdef ALLFAIL
  err = true;
#else
  err = strcmp(s,"()") != 0;
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);

  printf("%2d) ",++num);
  printf("%s%s%s",s=ntupToString(n1),sp(2),"<-- (\"i0\",\"i1\",\"i2\") (ntupToString) ");
#ifdef ALLFAIL
  err = true;
#else
  err = strcmp(s,"(\"i0\",\"i1\",\"i2\")") != 0;
#endif
  wrong = err?wrong+1:wrong;
  printf(err?" <<error #%d>>\n":"\n",wrong);

  /*
  printf("%2d) ",++num);
  printf("(checking freeTuple)");
  freeTuple(n2);
  printf("\n");
  */
  
  return 0;
}
