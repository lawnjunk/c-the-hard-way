#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
};

struct Database {
  struct Address rows[MAX_ROWS];
};

struct Connection {
  FILE *file;
  struct Database *db;
};

void die(const char *message){
  if(errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }
  exit(1);
};

void AddressPrint(struct Address *addr){
  printf("%d %s %s\n",
      addr->id, addr->name, addr->email);
}

void DatabaseLoad(struct Connection *conn){
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file); 
  if (rc != 1) die("Failed to load database.");
}

struct Connection *DatabaseOpen (const char *filename, char mode){
  struct Connection *conn = malloc(sizeof(struct Connection));
  if(!conn) die("Memory Error");

  conn->db = malloc(sizeof(struct Database));
  if (!conn->db) die("Memory error");

  if(mode == 'c') {
      conn->file = fopen(filename, "w");
  } else {
    conn->file = fopen(filename, "r+");

    if (conn->file){
      DatabaseLoad(conn);
    }
  }

  if(!conn->file) die("Failed to open the file");
  return conn;
}; 

void DatabaseClose(struct Connection *conn){
  if(conn){
    if (conn->file) fclose(conn->file);
    if (conn->db) free(conn->db);
    free(conn);
  }
}

void DatabaseWrite(struct Connection *conn){
  // set the file position pointer to the start of the file
  rewind(conn->file);

  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1) die("Failed to write databse.");

  rc = fflush(conn->file);
  if (rc == -1) die("cannot flush database.");
}

void DatabaseCreate(struct Connection *conn){
  for (int i=0; i < MAX_ROWS; i++){
    struct Address addr = {.id = i, .set = 0};
    conn->db->rows[i] = addr;
  }
}

void DatabaseSet(struct Connection *conn, int id, const char *name, const char *email){
  struct Address *addr = &conn->db->rows[id];
  if(addr->set) die("Allready set, delete it first");

  addr->set = 1;
  char *res = strncpy(addr->name, name, MAX_DATA);
  if (!res) die("Name copy fialed");

  res = strncpy(addr->email, email, MAX_DATA);
  if (!res) die("Email copy failed");
}

void DatabaseGet(struct Connection *conn, int id){
  struct Address *addr = &conn->db->rows[id];

  if(addr->set){
    AddressPrint(addr);
  } else {
    die("ID is not set");
  }
}

void DatabaseDelete(struct Connection *conn, int id){
  struct Address addr = {.id = id, .set = 0};
  conn->db->rows[id] = addr;
}

void DatabaseList(struct Connection *conn){
  struct Database *db = conn->db;

  for (int i=0; i<MAX_ROWS; i++){
    struct Address *cur = &db->rows[i];

    if(cur->set){
      AddressPrint(cur);
    }
  }
}

int main(int argc, char *argv[]){
  if(argc < 3) die("USAGE: ext17 <dbfile> <action> [action params]");

  char *filename = argv[2];
  char action = argv[1][0];
  struct Connection *conn = DatabaseOpen(filename, action);
  int id = 0;

  if(argc > 3) id = atoi(argv[3]);
  if(id >= MAX_ROWS) die("There is not that many records.");

  switch(action){
    case 'c':
      DatabaseCreate(conn);
      DatabaseWrite(conn);
      break;
    case 'g':
      if (argc != 4) die("Need an id to get");
      DatabaseGet(conn, id);
      break;
    case 's':
      if(argc != 6) die("Need id, name, email to set.");
      DatabaseSet(conn, id, argv[4], argv[5]);
      DatabaseWrite(conn);
      break;
    case 'd':
      if(argc != 4) die("Need id to delete");
      DatabaseDelete(conn, id);
      DatabaseWrite(conn);
      break;
    case 'l':
      DatabaseList(conn);
      break;
    default: 
      die("Invalid action:\nc=create\ng=get\ns=set\nd=del\nl=list");
  }

  DatabaseClose(conn);

  return 0;
}
