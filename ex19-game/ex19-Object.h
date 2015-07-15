#ifndef _object_h
#define _object_h

typedef enum {
  NORTH, SOUTH, EAST, WEST
} Direction;

typedef struct {
  char *description;
  int (*init)(void *self);
  void (*describe)(void *self);
  void (*destroy)(void *self);
  void *(*move)(void *self,  Direction direction);
  int (*attack)(void *self, int damage);
} Object;

int ObjectInit(void *self);
void ObjectDescribe(void *self);
void ObjectDestroy(void *self);
void *ObjectMove(void *self,  Direction direction);
int ObjectAttack(void *self, int damage);
void *ObjectNew(size_t size, Object proto, char *description);

#define NEW(T,N) ObjectNew(sizeof(T), T##Proto, N)
#define _(N) proto.N
#endif
