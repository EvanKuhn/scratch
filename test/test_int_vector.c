#include "test_int_vector.h"
#include "int_vector.h"
#include "minunit.h"
#include <stdio.h>
#include <string.h>

static char* test_vector_new() {
  int_vector* v = int_vector_new(1);
  mu_assert("int_vector_new() didn't create empty vector", int_vector_size(v) == 0);
  return 0;
}

static char* test_vector_size() {
  int_vector* v = int_vector_new(1);
  int_vector_append(v, 123);
  int_vector_append(v, 456);
  mu_assert("int_vector_size() didn't return expected size", int_vector_size(v) == 2);
  return 0;
}


/*
TODO - tests these:
size_t      int_vector_size     (const int_vector* v);
size_t      int_vector_capacity (const int_vector* v);
void        int_vector_clear    (int_vector* v);
void        int_vector_reserve  (int_vector* v, size_t newsize);
void        int_vector_resize   (int_vector* v, size_t newsize);
int         int_vector_get      (int_vector* v, size_t i);
void        int_vector_set      (int_vector* v, size_t i, int value);
void        int_vector_append   (int_vector* v, int value);
int         int_vector_front    (int_vector* v);
int         int_vector_back     (int_vector* v);
*/

char* test_int_vector() {
  printf("Testing: int_vector\n");
  mu_run_test(test_vector_new);
  mu_run_test(test_vector_size);
  return 0;
}

