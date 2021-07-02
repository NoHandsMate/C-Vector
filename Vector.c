#include "Vector.h"

#define INITIAL_CAPACITY 4


typedef struct vec {

    VEC_TYPE* data;
    int capacity;
    int size;

} vector;


vector* init_vector() {
    
    vector* vec = malloc(sizeof(vector));
    vec->data = (VEC_TYPE*) malloc(sizeof(VEC_TYPE) * INITIAL_CAPACITY);
    vec->capacity = INITIAL_CAPACITY;
    vec->size = 0;
    return vec;
}

void resize_vector(vector* vec, int new_capacity) {


    VEC_TYPE* ptr = (VEC_TYPE*) realloc(vec->data, sizeof(VEC_TYPE) * new_capacity);

    if (ptr) {

        vec->data = ptr;

        #ifdef DEBUG_VECTOR
        printf("RESIZE VECTOR FROM CAPACITY %i to %i\n", vec->capacity, new_capacity);
        #endif
        
        vec->capacity = new_capacity;
    }

}

void add_element(vector* vec, VEC_TYPE element) {
    
    if(vec->size == vec->capacity) {
        resize_vector(vec, vec->capacity * 2);
    }

    vec->data[vec->size++] = element; // This evaluates initially like this: vec->data[vec->size], the vec->size is incremented;
                                      // Same as: vec->data[vec->size] = element;  vec->size++;
}

void delete_element(vector *vec, int index) {

    if (index < 0 || index >= vec->size) 
        return;

    VEC_TYPE* ptr = &vec->data[index];
    ptr = NULL;

    for (int i = index; i < vec->size - 1; ++i) {
        vec->data[i] = vec->data[i + 1];
        VEC_TYPE* ptr = &vec->data[i + 1];
        ptr = NULL;
    }

    vec->size--;

    if(vec->size > 0 && vec->size == vec->capacity / 4) {
        resize_vector(vec, vec->capacity / 2);  // If the "used" cells are 1/4 of the total, half the capacity
    }
    
}

VEC_TYPE* get_element(vector* vec, int index) {

    if (index >= 0 && index < vec->size) {
        return &vec->data[index];
    }

    return NULL;
}

void clear_vec(vector *vec) {

    for (int i = 0; i < vec->size; ++i) {
        VEC_TYPE* ptr = &vec->data[i];
        ptr = NULL;
    }

    vec->size = 0;
    vec->capacity = INITIAL_CAPACITY;
    resize_vector(vec, vec->capacity);
}


void free_vec(vector *vec) {
    free(vec->data);
    free(vec);
}

VEC_TYPE back(vector *vec ) {
    int index = vec->size - 1;
    return vec->data[index];
}

VEC_TYPE  get_size(vector *vec) {
    return vec->size;
}

VEC_TYPE  get_capacity(vector *vec) {
    return vec->capacity;
}