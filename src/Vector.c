#include "../include/Vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdbool.h>

typedef enum {
    VECTOR_SUCCESS,
    VECTOR_FAILURE,
    VECTOR_OUT_OF_MEMORY
} VectorStatus;

Vector *vector_create(size_t element_size);
void vector_destroy(Vector *vec);
VectorStatus vector_push_back(Vector *vec, void *element);
Vector *create_vector(size_t size, int type);
void *vector_at(Vector *vec, size_t index);
bool vector_empty(Vector *vec);
size_t vector_size(Vector *vec);
size_t vector_capacity(Vector *vec);



#define VALID_TYPE(t) ((t) == INT || (t) == FLOAT || (t) == CHAR || (t) == STR)

// Compile-time assertion (Ensures invalid types are caught at compile time)
static_assert(VALID_TYPE(INT), "Invalid type used in vector creation");
#endif // VECTOR_H
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define CHAR 4
#define STR 5

typedef struct {
    size_t element_size;
    size_t size;
    size_t capacity;
    void *data;
    int type; // Add the type field
} Vector;

MemoryPool *create_pool(size_t block_size) {
    MemoryPool *pool = (MemoryPool *)malloc(sizeof(MemoryPool));
    if (!pool) return NULL;
    
    pool->blocks = malloc(block_size);
    if (!pool->blocks) {
        free(pool);
        return NULL;
    }
    
    pool->block_size = block_size;
    pool->used = 0;
    return pool;
}

void *pool_alloc(MemoryPool *pool, size_t size) {
    if (pool->used + size > pool->block_size) {
        return NULL; 
    }
    
    void *ptr = (char *)pool->blocks + pool->used;
    pool->used += size;
    return ptr;
}

void destroy_pool(MemoryPool *pool) {
    if (pool) {
        free(pool->blocks);
        free(pool);
    }
}

// Vector Functions
Vector *vector_create(size_t element_size) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    if (!vec) return NULL;

    vec->element_size = element_size;
    vec->capacity = 4;
    vec->size = 0;
    vec->data = malloc(vec->capacity * element_size);
    
    if (!vec->data) {
        free(vec);
        return NULL;
    }
    
    return vec;
}

void vector_destroy(Vector *vec) {
    if (vec) {
        free(vec->data);
        free(vec);
    }
}
VectorStatus vector_push_back(Vector *vec, void *element) {
    if (!vec || !element) return VECTOR_FAILURE;

    if (vec->size == vec->capacity) {
        size_t new_capacity = vec->capacity * 2;
        void *new_data = realloc(vec->data, new_capacity * vec->element_size);
        
        if (!new_data) return VECTOR_OUT_OF_MEMORY;

        vec->data = new_data;
        vec->capacity = new_capacity;
    }

    memcpy((char *)vec->data + vec->size * vec->element_size, element, vec->element_size);
    vec->size++;
    return VECTOR_SUCCESS;
}

Vector *create_vector(size_t size, int type) {
    if (!VALID_TYPE(type)) {
        fprintf(stderr, "Error: Invalid vector type\n");
        return NULL;  // Return NULL if an invalid type is passed
    }
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    if (!vec) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }
    vec->element_size = sizeof(type); // Initialize element_size
    vec->capacity = size > 0 ? size : 4; // Initialize capacity
    vec->size = 0; // Initialize size
    vec->type = type; // Initialize type
    vec->data = malloc(vec->capacity * vec->element_size);
    if (!vec->data) {
        free(vec);
        return NULL;
    }
    return vec;
}

void *vector_at(Vector *vec, size_t index) {
    if (!vec || index >= vec->size) return NULL;
    return (char *)vec->data + index * vec->element_size;
}

bool vector_empty(Vector *vec) {
    return vec->size == 0;
}

size_t vector_size(Vector *vec) {
    return vec->size;
}

size_t vector_capacity(Vector* vector){
    return vector->capacity;
}

int push_back_int(Vector *vec, int value) {
    if (!vec) return ERR_NULL_POINTER;
    if (vec->type != INT) return ERR_INVALID_TYPE;
    // Logic to push back an int
    return SUCCESS;
}

int push_back_float(Vector *vec, float value) {
    if (!vec) return ERR_NULL_POINTER;
    if (vec->type != FLOAT) return ERR_INVALID_TYPE;
    // Logic to push back a float
    return SUCCESS;
}

int push_back_double(Vector *vec, double value) {
    if (!vec) return ERR_NULL_POINTER;
    if (vec->type != DOUBLE) return ERR_INVALID_TYPE;
    return SUCCESS;
}
