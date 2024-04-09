#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int* array;
    size_t used;
    size_t size;
} DynamicArray;

void initializeArray(DynamicArray* a, size_t initialSize) 
{
    a->array = (int*)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(DynamicArray* a, int element) 
{
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int*)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
    printf("Inserted %d. Size of array: %lu\n", element, a->size);
}

void freeArray(DynamicArray* a) 
{
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

int main() 
{
    DynamicArray a;
    initializeArray(&a, 5);
    for (int i = 0; i < 100; i++)
    {
        insertArray(&a, i);
    }
    printf("21st element of the array: %d\n", a.array[20]);
    freeArray(&a);
}
