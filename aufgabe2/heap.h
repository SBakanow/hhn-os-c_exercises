//
// Created by Marvin Simon on 23.11.21.
//

#ifndef HHN_C_HEAP_H
#define HHN_C_HEAP_H

#include <stddef.h>

typedef struct Heap
{
    struct Heap *previousEntry;
    struct Heap *nextEntry;
    int position;
    int memory;
} Heap_t;

static Heap_t* heapMemory = NULL;

Heap_t *allocateHeap();

void deallocateHeap(Heap_t* heap);

#endif //HHN_C_HEAP_H
