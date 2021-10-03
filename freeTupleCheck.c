#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ntuple.h"

int main(void) {
  ntuple n2 = newTuple(50,
		"i0","i1","i2","i3","i4","i5","i6","i7","i8","i9",
		"i10","i11","i12","i13","i14","i15","i16","i17","i18","i19",
		"i20","i21","i22","i23","i24","i25","i26","i27","i28","i29",
		"i30","i31","i32","i33","i34","i35","i36","i37","38","i39",
		"i40","i41","i42","i43","i44","i45","i46","i47","i48","i49");
  printf("checking freeTuple");
  freeTuple(n2);
  printf(" - seems ok\n");
  return 0;
}