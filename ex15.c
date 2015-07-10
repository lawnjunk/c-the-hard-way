#include <stdio.h>

int main(int argc, char *argv[]){
  int ages[] = {23, 43, 12, 89, 2};
  char *names[] = {
    "fol", "nuf",
    "bal", "lulf", "guuf"
  };

  // get the ages of sizes
  int agesCount = sizeof(ages) / sizeof(int);
  
  for (int i=0; i<agesCount; i++){
    printf("%s has %d years alive.\n", names[i], ages[i]);
  }

  printf(" ----------------------- \n");

  //setup the pointers to the start of the arrays
  int *curAge = ages;
  char **curName = names;

  for (int i=0; i<agesCount; i++){
    printf("%s has %d years alive.\n", *(curName+i), *(curAge+i));
  }

  printf(" ----------------------- \n");

  // third way
  for(int i=0; i<agesCount; i++){
    printf("%s is %d years old again.\n", curName[i], curAge[i]);
  }
  
  printf(" ----------------------- \n");
  
  // fourth waty
  for(curName = names, curAge = ages; (curAge - ages) < agesCount; curName++, curAge++){
    printf("this way %s is still %d years old\n", *curName, *curAge);
  }

  return 0;
}

