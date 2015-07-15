#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message){
  if (errno){
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }
}

// type def creates a fake type
// this one is for a function pointer
typedef int(*compareCb)(int a, int b);

// buble sort
int *bubbleSort (int *numbers, int count, compareCb cmp){
  int temp = 0;
  int i = 0;
  int j = 0;
  int *target = malloc(count * sizeof(int));
if(!target) die("Memory error.");
  memcpy(target, numbers, count *sizeof(int));

  for(i=0; i<count; i++){
    for(j=0; j<count -1; j++){
      if(cmp(target[j], target[j+1]) > 0){
        temp = target[j+1];
        target[j+1] = target[j];
        target[j] = temp;
      }
    }
  }
  return target;
}

int sortedOrder(int a, int b){
  return a - b;
}

int reversedOrder(int a, int b){
  return b -a;
}

int strageOrder(int a, int b){
  if(a==0 || b==0){
    return 0;
  } else {
    return a%b;
  }
}

void testSorting(int *numbers, int count, compareCb cmp){
  int i =0;
  int *sorted = bubbleSort(numbers, count, cmp);

  if(!sorted) die("Failed to sort as requested");
  for (i=0; i< count; i++){
    printf("%d ", sorted[i]);
  }
  printf("\n");
  free(sorted);
}

int main(int argc, char *argv[]){
  if (argc < 2) die("USAGE: ex18 2 3 4 1 6");

  int count = argc - 1;
  int i = 0;
  char **inputs = argv + 1;
  
  int *numbers = malloc(count * sizeof(int));
  if(!numbers) die("Memory Error");
  
  for(i=0; i<count; i++){
    numbers[i] = atoi(inputs[i]);
  } 

  testSorting(numbers, count, sortedOrder);
  testSorting(numbers, count, reversedOrder);
  testSorting(numbers, count, strageOrder);

  return 0;
}
