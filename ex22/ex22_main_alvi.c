#include "dbg.h"
#include "ex22_alvi.h"
#include <stdio.h>
#include <stdlib.h>

const char *MY_NAME = "Zed A. Shaw";
const int THE_SIZE = 5;

void scope_demo(int count) {
  log_info("count is: %d", count);

  if (count > 10) {
    int numbers = 100; // BAD! BUGS!

    log_info("count in this scope is %d", numbers);
  }

  log_info("count is at exit: %d", count);

  count = 3000;

  log_info("count after assign: %d", count);
}

int main(int argc, char *argv[]) {
  struct State *state = malloc(sizeof(struct State));
  check_mem(state);

  set_age(state, 5);
  set_size(state, THE_SIZE);

  // test out THE_AGE accessors
  log_info("My name: %s, age: %d", MY_NAME, get_age(state));

  set_age(state, 100);

  log_info("My age is now: %d", get_age(state));

  // test out THE_SIZE extern
  log_info("THE_SIZE is: %d", THE_SIZE);
  print_size(state);

  log_info("THE SIZE is now: %d", THE_SIZE);
  print_size(state);

  // test the ratio function static
  log_info("Ratio at first: %f", update_ratio(2.0));
  log_info("Ratio again: %f", update_ratio(10.0));
  log_info("Ratio once more: %f", update_ratio(300.0));

  // test the scope demo
  int count = 4;
  scope_demo(count);
  scope_demo(count * 20);

  log_info("count after calling scope_demo: %d", count);

error:
  if (state)
    free(state);
  return -1;

  return 0;
}
