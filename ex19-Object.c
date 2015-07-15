#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ex19.h"
#include <assert.h>

int ObjectInit(void *self){
  // do nothing
  return 1;
}

void ObjectDescribe(void *self){
  Object *obj = self;
  printf("%s.\n", obj->description);
}

void ObjectDestroy(void *self){
  Object *obj = self;

  if(obj){
    if (obj->description) free(obj->description);
    free(obj);
  }
}

void ObjectMove(void *self,  Direction direction);

int ObjectAttack(void *self, int damage);

void *ObjectNew(size_t size, Object proto, char *description);

