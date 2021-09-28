#include <stdbool.h>

#ifndef TUPLE_H
#define TUPLE_H

#define MAX_ARITY 50 

struct ttype {
  int arity;
  char *items[MAX_ARITY];
};

typedef struct ttype *ntuple;

/* note that passing NULL for a tuple to any routine is undefined */

char *get(int n,ntuple t);
/* returns the nth item in the tuple t; like arrays in C the
   first item is indexed by 0. Function is undefined if item
   does not exist */
void put(int n, char *s, ntuple t);
/* inserts s at position n in t, replacing the item (do
   not free it) at n if it already exists. If n == arity+1,
   tuple increases in size. Adding to a "full" tuple or if n is
   illegal the operation is undefined. Index 0 is the first 
   item in the tuple. */

ntuple newTuple(int n,...);
/* returns a new n-tuple; see notes in handout on writing functions
   with varying number of arguments. Examples:
   t = newTuple(0);                     t == ()
   t = newTuple(2,"hi","mom");          t == ("hi","mom")
   t = newTuple(6,"","1","2","3","4","5"); t == ("","1","2","3","4","5") */

void freeTuple(ntuple);
// frees all strings in tuple AND the structure itself

bool equal(ntuple t1, ntuple t2);
/* returns true it t1==t2, false otherwise. Two tuples are
   equivalent if their arities are the same and all items 
   in one are identical to the correspoinding items in the
   other */

int arity(ntuple); // returns the arity of the tuple
bool isNtuple(ntuple t,int n); // returns true if tuple has an arity of n

char *ntupToString(ntuple t);
/* returns a string representation of t. Entire tuple should be 
   delimited by (), separated by commas, with every item in 
   double quotes and no spaces e.g. (), ("go","away","now",""). 
   String returned should be exactly the correct length to hold
   the tuple. */

#endif

