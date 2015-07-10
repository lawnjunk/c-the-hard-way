#include <stdio.h>

int main(int argc, char *argv[]){
  int i = 0;
  while(i < argc){
    printf("arg %d: %s\n", i, argv[i]);
    i++;
  }


  if (-1){
    printf("hello there\n");
  }

  return 0;
}
