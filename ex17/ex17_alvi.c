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

  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if (!rc)
    die("Failed to load to Database");
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

void Database_create(struct Connection *conn) {

  int i = 0;
  for (i = 0; i < MAX_ROWS; i++) {
    /* Make a Prototype to initialize it */
    struct Address addr = {.id = i, .set = 0};
    /* and then assigning it */
    conn->db->rows[i] = addr;
  }
}

void Database_close(struct Connection *conn) {
  if (!conn)
    die("Memory Error");

  if (conn->file)
    fclose(conn->file);

  if (conn->db)
    free(conn->db);

  free(conn);
}

int main(int argc, char *argv[]) {

  if (argc < 3)
    die("USAGE: ex17 <dbfile> <action> [action params]");

  char *filename = argv[1];
  char action = argv[2][0];

  struct Connection *conn = Database_open(filename, action);
  int id = 0;

  if (argc > 3)
    id = atoi(argv[3]);

  if (id >= MAX_ROWS)
    die("There's not that many records.");

  switch (action) {
  case 'c':
    Database_create(conn);
    break;

  case 'g':
    if (argc != 6)
      die("Need id, name, email to set");

    // Database_set(conn, id, argv[4], argv[5]);
    // Database_write(conn);

    die("TODO: Not Implemented");
    break;

  case 'd':
    if (argc != 4)
      die("Need id to delete");

    // Database_delete(conn, id);
    // Database_write(conn);
    die("TODO: Not Implemented");
    break;

  case 'l':
    // Database_list(conn);
    die("TODO: Not Implemented");
    break;

  default:
    die("Invalid action: c=create, g=get, s=set, d=del, l=list");
  }

  Database_close(conn);

  return 0;
}