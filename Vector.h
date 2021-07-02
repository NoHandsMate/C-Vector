#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>


typedef float VEC_TYPE;        // Change this to change the type of the vector
// #define DEBUG_VECTOR


typedef struct vec vector;

vector* init_vector();
void add_element(vector* vec, VEC_TYPE element);
void delete_element(vector* vec, int index);
VEC_TYPE* get_element(vector* vec, int index);

void clear_vec(vector* vec);
VEC_TYPE back(vector* vec);
VEC_TYPE get_size(vector* vec);
VEC_TYPE get_capacity(vector* vec);


void free_vec(vector* vec);

#endif