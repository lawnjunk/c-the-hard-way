#ifndef _ex19_Game_h 
#define _ex19_Game_h

#include "ex19-Object.h"

struct Monster {
  Object proto;
  int hitPoints;
};

typedef struct Monster Monster;

int MonsterAttack(void *self, int damage);
int MonsterInit(void *self);

struct Room {
  Object proto;

  Monster *badGuy;
  
  struct Room *north;
  struct Room *south;
  struct Room *east;
  struct Room *west;
};

typedef struct Room Room;

struct Map {
  Object proto;
  Room *start;
  Room *location;
};

void *RoomMove(void *self, Direction direction);
int RoomAttack(void *self, int damage);
int RoomInit(void *self);

typedef struct Map Map;

void *MapMove(void *self, Direction direction);
int MapAttack(void *self, int damage);
int MapInit(void *self);

#endif
