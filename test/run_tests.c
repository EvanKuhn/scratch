#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "test_string.h"
#include "test_int_vector.h"

int tests_run = 0;

int main(int argc, char **argv) {
  // Run all tests
  char* msg = NULL;
  if(!msg) msg = test_string();
  if(!msg) msg = test_int_vector();

  // Print results
  printf("%s\n", (msg ? msg : "ALL TESTS PASSED"));
  printf("Tests run: %d\n", tests_run);

  // Exit with success or failure
  return msg != 0;
}
