#include <stdio.h>
#include <ctype.h>

// prototype the functions
void printArguments(int argc, char *argv[]);
void printLetters(char str[]);
int canPrintIt(char ch);

int main(int argc, char *argv[]){
  if (argc != 2) {
    printf("dont have any args you failled.n\n");
    return 1;
  }

  printArguments(argc, argv);
  return 0;
}

void printArguments(int argc, char *argv[]){
  for (int i=0; i< argc; i++){
    printLetters(argv[1]);
  }
}

void printLetters(char str[]){
  for(int i=0; str[i] != '\0'; i++){
    char ch = str[i];

    if(canPrintIt(ch)){
      printf("%c == %d\n", ch, ch);
    }
  }
}
int canPrintIt(char ch){
  return isalpha(ch) || isblank(ch);
}
