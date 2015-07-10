#include <stdio.h>

int main(){

  /// ex1 -- without pointer arithmatic;
  int ex1[] = { 11,13,15,17};
  int ex1Length = sizeof(ex1)/sizeof(int);

  for (int i=0; i<ex1Length; i++){
    printf("ext1[%d]:  %d\n", i, ex1[i]);
  }

  /// ex2 -- with pointer arithmatic;
  int *ex2 = ex1;

  int *cur = ex2;
  while ( cur < (ex2 + ex1Length) ){
    printf("ext[%d]:  %d\n", cur, *(cur));
    cur++;
  }

}
