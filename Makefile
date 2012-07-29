SHELL   = /bin/sh
CC      = gcc
CFLAGS  = -c -std=c99 -Wall -Isrc -Ilib
SOURCES = src/string_class.c src/int_vector.c test/test_string.c test/test_int_vector.c test/run_tests.c
OBJECTS = $(SOURCES:.c=.o)

all: test
test: $(OBJECTS) bin/run_tests

bin/run_tests: $(OBJECTS)
	[ -e bin ] || mkdir bin
	$(CC) $(OBJECTS) -o bin/run_tests

src/string_class.o:     src/string_class.h
src/int_vector.o:       src/int_vector.h
test/test_string.o:     test/test_string.h
test/test_int_vector.o: test/test_int_vector.h

clean:
	find . -name "*.o" -exec rm -fv {} \;
	rm -vf bin/*
