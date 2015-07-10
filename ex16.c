#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person *PersonCreate(char *name, int age, int height, int weight){
  struct Person *who = malloc(sizeof(struct Person));
  assert(who != NULL);

  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
}

void PersonDestroy(struct Person *who){
  assert (who != NULL);

  free(who->name);
  free(who);
}

void PersonPrint(struct Person *who){
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}


int main(){
 // make a person
 struct Person *slug = PersonCreate( "slug", 11, 4, 44);
 // print them
 printf("slug is at mem location %p\n", slug);
 PersonPrint(slug);

 // change there data
 slug->age += 15;
 
 // print them 
 printf("slug is 15 years older\n");
 PersonPrint(slug);
}
