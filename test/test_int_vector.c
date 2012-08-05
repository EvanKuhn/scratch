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

static char* test_vector_capacity() {
  int_vector* v = int_vector_new(1);
  mu_assert("int_vector_capacity() didn't return expected value (1)",
            int_vector_capacity(v) == 1);
  int_vector_reserve(v, 10);
  mu_assert("int_vector_capacity() didn't return expected value (10)",
            int_vector_capacity(v) == 10);
  return 0;
}

static char* test_vector_clear() {
  int_vector* v = int_vector_new(1);
  int_vector_resize(v, 10);
  mu_assert("int_vector_size() didn't return expected value (10)",
            int_vector_size(v) == 10);
  mu_assert("int_vector_capacity() didn't return expected value (10)",
            int_vector_capacity(v) == 10);
  int_vector_clear(v);
  mu_assert("int_vector_size() didn't return expected value (0)",
            int_vector_size(v) == 0);
  mu_assert("int_vector_capacity() didn't return same expected value (10)",
            int_vector_capacity(v) == 10);
  return 0;
}

static char* test_vector_reserve() {
  int_vector* v = int_vector_new(1);
  mu_assert("int_vector_capacity() didn't return expected initial value (1)",
            int_vector_capacity(v) == 1);
  int_vector_reserve(v, 22);
  mu_assert("int_vector_capacity() didn't return expected new value (22)",
            int_vector_capacity(v) == 22);
  int_vector_reserve(v, 5);
  mu_assert("int_vector_capacity() should not decrease capacity",
            int_vector_capacity(v) == 22);
  return 0;
}

static char* test_vector_resize() {
  int_vector* v = int_vector_new(1);
  // TODO
  return 0;
}

static char* test_vector_get() {
  int_vector* v = int_vector_new(1);
  // TODO
  return 0;
}

static char* test_vector_set() {
  int_vector* v = int_vector_new(1);
  // TODO
  return 0;
}

static char* test_vector_append() {
  int_vector* v = int_vector_new(1);
  // TODO
  return 0;
}

static char* test_vector_front() {
  int_vector* v = int_vector_new(1);
  // TODO
  return 0;
}

static char* test_vector_back() {
  int_vector* v = int_vector_new(1);
  // TODO
  return 0;
}

char* test_int_vector() {
  printf("Testing: int_vector\n");
  mu_run_test(test_vector_new);
  mu_run_test(test_vector_size);
  mu_run_test(test_vector_capacity);
  mu_run_test(test_vector_clear);
  mu_run_test(test_vector_reserve);
  mu_run_test(test_vector_resize);
  mu_run_test(test_vector_get);
  mu_run_test(test_vector_set);
  mu_run_test(test_vector_append);
  mu_run_test(test_vector_front);
  mu_run_test(test_vector_back);
  return 0;
}

