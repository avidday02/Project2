  /* Project #2
   EGRE245 Fall 2021
   D. Adams <-- I used my name here! */
  
  #include <stdio.h>
  #include <stdarg.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>
  #include "ntuple.h"
  #include "unity.h"

/* returns the nth item in the tuple t; like arrays in C the
   first item is indexed by 0. Function is undefined if item
   does not exist */
char *get(int n,ntuple t){
  return t -> items[n];
}

 /* inserts s at position n in t, replacing the item (do
   not free it) at n if it already exists. If n == arity,
   tuple increases in size. Adding to a "full" tuple or if n is
   illegal the operation is undefined. Index 0 is the first 
   item in the tuple. */
void put(int n, char *s, ntuple t){
  char* stringVar = malloc(sizeof(char)*strlen(s)+1);
  strcpy(stringVar, s);
  if( n == arity(t)){
      t -> arity++;
    }
    t -> items[n] = stringVar;
}

/* returns a new n-tuple; see notes in handout on writing functions
   with varying number of arguments. Examples:
   t = newTuple(0);                     t == ()
   t = newTuple(2,"hi","mom");          t == ("hi","mom")
   t = newTuple(6,"","1","2","3","4","5"); t == ("","1","2","3","4","5") */
ntuple newTuple(int n,...){
  va_list list;
  va_start(list, n);
  ntuple t = malloc(sizeof(struct ttype));
  t -> arity = n;
  for(int index1 = 0; index1 < n; index1++){
    put(index1,va_arg(list, char*), t);
    t -> arity = index1 + 1;
  }
    va_end(list);  
  return t;
}


// frees all strings in tuple AND the structure itself
void freeTuple(ntuple t){
  int n = arity(t);
  for(int i = 0; i <= n; i++){
    free(t -> items[i]);
  }
  free(t);
}

/* returns true it t1==t2, false otherwise. Two tuples are
   equivalent if their arities are the same and all items 
   in one are identical to the correspoinding items in the
   other */
bool equal(ntuple t1, ntuple t2){
  if(arity(t1) == arity(t2)){
    for(int i = 0; i < arity(t1); i++){
      if(!strcmp(get(i, t1),get(i, t2))){
      }
      else{
        return false;
      }
    }
  } 
  else{
    return false;
  }
}

// returns the arity of the tuple
int arity(ntuple t){
  return t -> arity;
} 


// returns true if tuple has an arity of n
bool isNtuple(ntuple t,int n){
  return (t -> arity == n);
}


/* returns a string representation of t. Entire tuple should be 
   delimited by (), separated by commas, with every item in 
   double quotes and no spaces e.g. (), ("go","away","now",""). 
   String returned should be exactly the correct length to hold
   the tuple. */
char *ntupToString(ntuple t){
  
  //need to delineate quotation for strings \""
  //when call tuple to print we want to include ("...","...")

 /* int n = t -> arity;
  char arr[100] = "";

  for(int i = 0; i > n; i++){

  }
  return arr[];*/
}

