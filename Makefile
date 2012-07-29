SHELL=/bin/sh
CC=gcc
CFLAGS = -c -std=c99 -Wall -Isrc -Ilib
SOURCES=src/string_class.c src/int_vector.c test/test_string.c test/test_int_vector.c test/run_tests.c
OBJECTS=$(SOURCES:.c=.o)

all: src test

src: $(OBJECTS)
tests: $(OBJECTS) bin/run_tests

clean:
	find . -name "*.o" -exec rm -fv {} \;
	rm -vf bin/*

src/string_class.o: src/string_class.c
	$(CC) $(CFLAGS) $< -o src/string_class.o

src/int_vector.o: src/int_vector.c
	$(CC) $(CFLAGS) $< -o src/int_vector.o

test/test_string.o: test/test_string.c
	$(CC) $(CFLAGS) $< -o test/test_string.o

test/test_int_vector.o: test/test_int_vector.c
	$(CC) $(CFLAGS) $< -o test/test_int_vector.o

test/run_tests.o: test/run_tests.c
	$(CC) $(CFLAGS) $< -o test/run_tests.o

bin/run_tests:
	$(CC) $(OBJECTS) -o bin/run_tests
