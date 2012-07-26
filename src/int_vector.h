#ifndef INT_VECTOR_H
#define INT_VECTOR_H

#include <string.h>

typedef struct int_vector int_vector;

int_vector* int_vector_new      (size_t capacity);
void        int_vector_free     (int_vector* v);
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

#endif
