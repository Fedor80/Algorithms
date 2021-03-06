#include <stdlib.h>
#include "vector.h"

struct Vector
{
    Data* data;
    size_t capacity = 0;
    size_t size = 0;
};

Vector *vector_create()
{
    Vector* vector = new Vector;
    vector->data = new Data[0];
    return vector;
}

void vector_delete(Vector *vector)
{
    delete vector->data;
    delete vector;
}

Data vector_get(const Vector *vector, size_t index)
{
    return vector->data[index];
}

void vector_set(Vector *vector, size_t index, Data value)
{
    if (index < vector->size)
    {
        vector->data[index] = value;
    }
}

void vector_pushback(Vector* vector, Data value)
{
    if (vector->size >= vector->capacity)
    {
        vector_recapacity(vector, vector->size * 2);
    }
    vector->data[vector->size] = value;
    vector->size++;
}

size_t vector_size(const Vector *vector)
{
    return vector->size;
}

void vector_resize(Vector *vector, size_t size)
{
    if (size > vector->capacity)
    {
        vector_recapacity(vector, size * 2);
    }
    vector->size = size;
}

void vector_recapacity(Vector* vector, size_t cap)
{
    if (cap == 0) cap = 1;
    if (cap <= vector->capacity)
    {
        vector->capacity = cap;
    }
    else
    {
        size_t new_cap = 0;
        if (cap > vector->capacity * 2)
        {
            new_cap = cap;
        }
        else
        {
            new_cap = vector->capacity * 2;
        }
        Data* elem = new Data[new_cap];

        for (int i = 0; i < vector->capacity; i++)
        {
            elem[i] = vector->data[i];
        }
        int i = vector->capacity;
        if (i < 0) i = 0;
        for (i; i < new_cap; i++)
        {
            elem[i] = 0;
        }

        delete[] vector->data;
        vector->data = elem;
        vector->capacity = new_cap;
    }
}

size_t vector_capacity(const Vector* vector)
{
    return vector->capacity;
}