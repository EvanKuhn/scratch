//==============================================================================
// Class representing a vector of integers, much like C++'s std::vector<int>.
//
// Evan Kuhn, 2012-07-26
//==============================================================================
#ifndef INT_VECTOR_H
#define INT_VECTOR_H

#include <string.h> // size_t

typedef struct int_vector int_vector;

// Create a new vector with some capacity (will enforce a minimum of 1)
int_vector* int_vector_new(size_t capacity);

// Free a vector and its internal data
void int_vector_free(int_vector* v);

// Get the vector's size (current number of elements)
size_t int_vector_size(const int_vector* v);

// Get the vector's capacity (current memory allocated for storing elements)
size_t int_vector_capacity(const int_vector* v);

// Clear the vector by setting the size to 0. Capacity remains unchanged.
void int_vector_clear(int_vector* v);

// Reserve capacity for N elements
void int_vector_reserve(int_vector* v, size_t newsize);

// Resize to N elements
// - If smaller than the current capacity, it will just set the new size.
// - If larger than the current capacity, it will allocate new capacity.
void int_vector_resize(int_vector* v, size_t newsize);

// Get or set an element at index i
int  int_vector_get(int_vector* v, size_t i);
void int_vector_set(int_vector* v, size_t i, int value);

// Append an element, growing the vector's capacity as needed
void int_vector_append(int_vector* v, int value);

// Get the element at the front or back of the array
int int_vector_front(int_vector* v);
int int_vector_back (int_vector* v);

#endif
