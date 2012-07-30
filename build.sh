#!/bin/bash

gcc --std=c99 -Isrc -Ilib src/string_class.c src/int_vector.c \
  test/test_string.c test/test_int_vector.c test/run_tests.c -o bin/run_tests
