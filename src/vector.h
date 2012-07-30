//==============================================================================
// Macros for creating vector structs and functions, much like C++'s std::vector
//
// Evan Kuhn, 2012-07-29
//==============================================================================
#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h> // malloc
#include <string.h> // memcpy
#include <assert.h>

//==============================================================================
// Declare a vector
//==============================================================================
#define DECLARE_VECTOR(datatype, classname) \
typedef struct classname classname; \
classname*  classname##_new      (size_t capacity); \
void        classname##_free     (classname* v); \
size_t      classname##_size     (const classname* v); \
size_t      classname##_capacity (const classname* v); \
void        classname##_clear    (classname* v); \
void        classname##_reserve  (classname* v, size_t newsize); \
void        classname##_resize   (classname* v, size_t newsize); \
int         classname##_get      (classname* v, size_t i); \
void        classname##_set      (classname* v, size_t i, int value); \
void        classname##_append   (classname* v, int value);  \
int         classname##_front    (classname* v); \
int         classname##_back     (classname* v);

//==============================================================================
// Declare a vector
//==============================================================================
#define DEFINE_VECTOR(datatype, classname) \
struct classname { \
  datatype * data; /* The C array of data */ \
  size_t size;     /* Number of elements placed into the vector */ \
  size_t cap;      /* Total size of the data array */ \
}; \
\
classname* classname##_new(size_t capacity) { \
  if(capacity == 0) capacity = 1; \
  classname * v = malloc(sizeof(classname)); \
  v->data = malloc(capacity * sizeof(datatype)); \
  v->size = 0; \
  v->cap = capacity; \
  return v; \
} \
\
void classname##_free(classname* v) { \
  free(v->data); \
  free(v); \
} \
\
size_t classname##_size(const classname* v) { \
  return v->size; \
} \
\
size_t classname##_capacity(const classname* v) { \
  return v->cap; \
} \
\
void classname##_clear(classname* v) { \
  v->size = 0; \
} \
\
void classname##_reserve(classname* v, size_t mincap) { \
  /* Try to double capacity. If not enough, just use the new size. */ \
  size_t newcap = v->cap * 2; \
  if(newcap < mincap) newcap = mincap; \
  /* Allocate a new buffer and copy data over */ \
  datatype* newdata = malloc(newcap * sizeof(datatype)); \
  memcpy(newdata, v->data, v->size * sizeof(datatype)); \
  /* Free the old buffer and save the new one */ \
  free(v->data); \
  v->data = newdata; \
  v->cap  = newcap; \
} \
\
void classname##_resize(classname* v, size_t newsize) { \
  if(newsize > v->size) { \
    classname##_reserve(v, newsize); \
  } \
  v->size = newsize; \
} \
\
datatype classname##_get(classname* v, size_t i) { \
  assert(i < v->size); \
  return v->data[i]; \
} \
\
void classname##_set(classname* v, size_t i, datatype value) { \
  assert(i < v->size); \
  v->data[i] = value; \
} \
\
void classname##_append(classname* v, datatype value) { \
  if(v->size == v->cap) { \
    classname##_reserve(v, v->cap * 2); \
  } \
  v->data[v->size++] = value; \
} \
\
datatype classname##_front(classname* v) { \
  assert(v->size > 0); \
  return v->data[0]; \
} \
\
datatype classname##_back(classname* v) { \
  assert(v->size > 0); \
  return v->data[v->size - 1]; \
}

#endif VECTOR_H