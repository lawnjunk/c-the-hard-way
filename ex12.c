#include <stdio.h>

int main(int argc, char *argv[]){
  if (argc == 1){
    printf("you only have one argument. lame\n");
  } else if (argc > 1 && argc < 10){
    for (int i=0; i< argc; i++){
      printf("%s ", argv[i]);
    }
    printf("\n");
  } else {
    printf("You have way to manny fucin args, lul!\n");
  }
}
