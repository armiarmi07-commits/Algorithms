#include "vector.h"

struct Vector
{
    Data *data;
    size_t size;
    size_t capacity;
};

Vector *vector_create()
{
    Vector* vector = new Vector;
    vector->size = 0;
    vector->capacity = 0;
    vector->data = 0;
    return vector;
}

void vector_delete(Vector *vector)
{
    // TODO: free vector internals
    if (vector) {
        delete[] vector->data;
        delete vector;
    }
}

Data vector_get(const Vector *vector, size_t index)
{
    if (!vector || index >= vector->size) {
        return "";
    }
    return vector->data[index];
}

void vector_set(Vector *vector, size_t index, Data value)
{
    if (!vector || index >= vector->size) {
        return;
    }
    vector->data[index] = value;
}

size_t vector_size(const Vector *vector)
{
    if (vector ) {
        return vector->size;
    }
    return 0;
}

void vector_resize(Vector *vector, size_t size)
{
    if (vector == 0) {
        return;
    }
    if (size > vector->capacity) {
        size_t new_capacity = 1;
        while (new_capacity < size) {
            new_capacity *= 2;
        }
        Data* new_data = new Data[new_capacity];
        for (size_t i = 0; i < vector->size; i++) {
            new_data[i] = vector->data[i];
        }
        delete[] vector->data;
        vector->data = new_data;
        vector->capacity = new_capacity;
    }
    vector->size = size;
}
