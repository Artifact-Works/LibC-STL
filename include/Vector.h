#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include "error_codes.h"

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include "error_codes.h"

#ifdef DEBUG
    #define DEBUG_PRINT(msg) printf("DEBUG: %s\n", msg)
#else
    #define DEBUG_PRINT(msg)
#endif

#endif // VECTOR_H


#define VECTOR_POOL_BLOCK_SIZE 1024

typedef enum {
    VECTOR_SUCCESS,
    VECTOR_FAILURE,
    VECTOR_OUT_OF_MEMORY,
} VectorStatus;

typedef struct {
    void *data;
    size_t element_size;
    size_t capacity;
    size_t size;
} Vector;
typedef struct vectoriterator{
    Vector* vector;
    size_t pos;
    void *item;
} vector_iterator;
typedef struct MemoryPool {
    void *blocks;
    size_t block_size;
    size_t used;
} MemoryPool;

// memory pool
MemoryPool *create_pool(size_t block_size);
void *pool_alloc(MemoryPool *pool, size_t size);
void destroy_pool(MemoryPool *pool);

// vector
VectorStatus vector_push_back(Vector *vec, void *element);
Vector *vector_create(size_t element_size);
void vector_destroy(Vector *vec);
void *vector_at(Vector *vec, size_t index);
bool vector_empty(Vector *vec);
size_t vector_size(Vector *vec);
size_t vector_capacity(Vector* vec);

// vector iterators
vector_iterator* create_iterator(Vector *vector);
bool iterator_has_next(vector_iterator *itr);
void *iterator_next(vector_iterator* itr);
void destroy_iterator(vector_iterator *itr);
vector_iterator *iterator_front(Vector * vector);
#endif 
