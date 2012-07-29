#include <stdio.h>
#include "src/vector.h"

#define make_func(name) \
void name##_cool() { printf("in func!\n"); }
make_func(evan_is);

DECLARE_VECTOR(int, int_vector);
DEFINE_VECTOR(int, int_vector);

int main() {
  evan_is_cool();
  int_vector* vec = int_vector_new(3);
  printf("vector has size %zu\n", int_vector_size(vec));
  printf("vector has capacity %zu\n", int_vector_capacity(vec));
}
