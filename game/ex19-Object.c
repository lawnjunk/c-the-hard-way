#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ex19-Object.h"
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

void *ObjectMove(void *self,  Direction direction){
  printf("You cant go in that direction");
  return NULL;
}

int ObjectAttack(void *self, int damage){
  printf("you can't attack that.\n");
  return 0;
}

void *ObjectNew(size_t size, Object proto, char *description){
  if(!proto.init) proto.init = ObjectInit;
  if(!proto.describe) proto.describe = ObjectDescribe;
  if(!proto.destroy) proto.destroy = ObjectDestroy;
  if(!proto.attack) proto.attack = ObjectAttack;
  if(!proto.move) proto.move = ObjectMove;

  Object *el = calloc(1, size);
  *el = proto;
 
  el->description = strdup(description);

  if(!el->init(el)){
    el->destroy(el);
    return NULL;
  } else {
    return el;
  }
}
