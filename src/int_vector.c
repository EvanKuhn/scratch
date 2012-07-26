#include "int_vector.h"
#include <stdlib.h>
#include <assert.h>

struct int_vector {
  int* data;   // The C array of data
  size_t size; // Number of elements in the array
  size_t cap;  // The length of the C array of data
};

int_vector* int_vector_new(size_t capacity) {
  if(capacity == 0) capacity = 1;
  int_vector* v = malloc(sizeof(int_vector));
  v->data = malloc(capacity * sizeof(int));
  v->size = 0;
  v->cap = capacity;
  return v;
}

void int_vector_free(int_vector* v) {
  free(v->data);
  free(v);
}

size_t int_vector_size(const int_vector* v) {
  return v->size;
}

size_t int_vector_capacity(const int_vector* v) {
  return v->cap;
}

void int_vector_clear(int_vector* v) {
  v->size = 0;
}

void int_vector_reserve(int_vector* v, size_t mincap) {
  // Try to double capacity. If not enough, just use the new size.
  size_t newcap = v->cap * 2;
  if(newcap < mincap) newcap = mincap;
  // Allocate a new buffer and copy data over
  int* newdata = malloc(newcap * sizeof(int));
  memcpy(newdata, v->data, v->size * sizeof(int));
  // Free the old buffer and save the new one
  free(v->data);
  v->data = newdata;
  v->cap  = newcap;
}

void int_vector_resize(int_vector* v, size_t newsize) {
  if(newsize > v->size) {
    int_vector_reserve(v, newsize);
  }
  v->size = newsize;
}

int int_vector_get(int_vector* v, size_t i) {
  assert(i < v->size);
  return v->data[i];
}

void int_vector_set(int_vector* v, size_t i, int value) {
  assert(i < v->size);
  v->data[i] = value;
}

void int_vector_append(int_vector* v, int value) {
  if(v->size == v->cap) {
    int_vector_reserve(v, v->cap * 2);
  }
  v->data[v->size++] = value;
}

int int_vector_front(int_vector* v) {
  assert(v->size > 0);
  return v->data[0];
}

int int_vector_back(int_vector* v) {
  assert(v->size > 0);
  return v->data[v->size - 1];
}

