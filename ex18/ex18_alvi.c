#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Cases for pointer functions */
typedef int (*compare_cb)(int a, int b);

/* Helper Function: Used for Error Handling */
void die(const char *message) {

  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

int main(int argc, char *argv[]) {
  if (argc < 2)
    die("USAGE: ex18_alvi 4 3 1 5 6");

  return 0;
}