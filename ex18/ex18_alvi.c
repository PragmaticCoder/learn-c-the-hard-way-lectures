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

  int count = argc - 1;
  int i = 0;
  char **inputs = argv + 1;

  int *numbers = malloc(count * sizeof(int));
  if (!numbers)
    die("Memory Error");
  
  for(i = 0; i < count; i++)
    numbers[i] = atoi(inputs[i]);

  return 0;
}