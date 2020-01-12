#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Helper Function: Used for Error Handling */
void die(const char *message) {
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

int main(int argc, char *argv[]) { return 0; }