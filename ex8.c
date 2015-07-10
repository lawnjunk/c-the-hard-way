#include <stdio.h>

int main(int argc, char **argv){

  // arrays are sick 
  
  int areas[] = {10,11,12,13};
  char *name = "ZED";
  char full_name[] = {'z', 'e', 'd', ' ', 's', 'l', 'u', 'g', '\0'};

  printf("size of int: %ld\n", sizeof(int));

  int areaLength = (int) sizeof(areas) / sizeof(int);
  for (int i=0; i< areaLength; i++){
    printf("areas[%d]: %d ", i, areas[i] );
  }
  printf("\n");

  printf("who is %s?\n", name);
  printf("%s?... a maaad homie!\n", full_name);


  return 0;
}
