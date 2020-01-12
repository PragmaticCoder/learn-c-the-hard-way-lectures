#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
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

void die(const char *message) {

  if (errno)
    perror(message);
  else
    printf("ERROR: %s\n", message);

  exit(1);
}

void Database_load(struct Connection *conn) {
  printf("Got to Database_load function");
}

struct Connection *Database_open(const char *filename, const char mode) {

  struct Connection *conn = malloc(sizeof(struct Connection));
  if (!conn)
    die("Memory Error");

  conn->db = malloc(sizeof(struct Database));
  if (!conn->db)
    die("Memory error");

  if (mode == 'c')
    conn->file = fopen(filename, "w");
  else
    conn->file = fopen(filename, "r");

  if (conn->file) {
    Database_load(conn);
  }

  if (!conn->file)
    die("Failed to open the file");

  return conn;
}

int main(int argc, char *argv[]) {

  if (argc < 3)
    die("USAGE: ex17 <dbfile> <action> [action params]");

  char *filename = argv[1];
  char action = argv[2][0];

  struct Connection *conn = Database_open(filename, action);

  return 0;
}