#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19-Object.h"
#include "ex19-Game.h"

int MonsterAttack(void *self, int damage){
  Monster *monster = self;
  
  printf("You attack %s!\n", monster->_(description));

  monster->hitPoints -= damage;

  if(monster->hitPoints){
    printf("It is still alive.\n");
    return 0;
  } else {
    printf("It is deat!\n");
    return 1;
  }
}

int MonsterInit(void *self){
  Monster *monster = self;
  monster->hitPoints = 10;
  return 1;
}

Object MonsterProto = {
  .init = MonsterInit,
  .attack = MonsterAttack,
};

void *RoomMove(void *self, Direction direction ){
  Room *room = self;
  Room *next = NULL;

  if(direction == NORTH && room->north){
    printf("You go north, into:\n");
    next = room->north;
  } else if(direction == EAST && room->east){
    printf("You go east, into:\n");
    next = room->east;
  } else if(direction == SOUTH && room->south){
    printf("You go south, into:\n");
    next = room->south;
  } else if(direction == WEST && room->west){
    printf("You go west, into:\n");
    next = room->west;
  } else {
    printf("You cant go in that direction.");
    next = NULL;
  }
  if (next){
    next->_(describe)(next);
  }

  return next;
}

int RoomAttack(void *self, int damage){
  Room *room = self;
  Monster *monster = room->badGuy;
  
  if(monster) {
    monster->_(attack)(monster, damage);
    return 1;
  } else {
    printf("You flail in the air at nothing. Dummy.\n");
    return 0;
  }
}

Object RoomProto = {
  .move = RoomMove,
  .attack = RoomAttack,
};

void *MapMove(void *self, Direction direction){
  Map *map = self;
  Room *location = map->location;
  Room *next = NULL;

  next = location->_(move)(location, direction);

  if(next){
    map->location = next;
  }

  return next;
}

int MapAttack(void *self, int damage){
  Map* map = self;
  Room *location = map->location;

  return location->_(attack)(location, damage);
}

int MapInit(void *self){
  Map *map = self;
  Room *hall = NEW(Room, "The great Hall");
  Room *throne = NEW(Room, "The throe Room");
  Room *arena = NEW(Room, "The arena, with the minotaur");
  Room *kitchen = NEW(Room, "Kitchen, you have the knife now");

  arena->badGuy = NEW(Monster, "The evil minotaur");
  
  hall->north = throne;

  throne->west = arena;
  throne->east = kitchen;
  throne->south = hall;

  arena->east = throne;
  kitchen->west = throne;

  map->start = hall;
  map->location = hall;
  return 1;
}

Object MapProto= {
  .init = MapInit,
  .move = MapMove,
  .attack = MapAttack
};

int processInput(Map *game){
  printf("\n> ");

  char ch = getchar();
  getchar(); // eat ENTER

  int damage = rand() % 4;

  switch(ch){
    case -1:
      printf("dont leave! looser.\n");
      return 0;
      break;
    case 'n':
      game->_(move)(game, NORTH);
      break;
    case 's':
      game->_(move)(game, SOUTH);
      break;
    case 'e':
      game->_(move)(game, EAST);
      break;
    case 'w':
      game->_(move)(game, WEST);
      break;
    case 'a':
      game->_(attack)(game,damage);
      break;
    case 'l':
      printf("You can go:\n");
      if(game->location->north) printf("north\n");
      if(game->location->south) printf("south\n");
      if(game->location->east) printf("east\n");
      if(game->location->west) printf("west\n");
      break;
    default:
      printf("what?: %d\n", ch);
  }
  return 1;
}

int main(int argc, char *argv[]){
  srand(time(NULL));
  Map *game = NEW(Map, "The Hall of the Minotaur");

  printf("You can enter the ");
  game->location->_(describe)(game->location);
  while(processInput(game)){
  }
  return 0;
};



