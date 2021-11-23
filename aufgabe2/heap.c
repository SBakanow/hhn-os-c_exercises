#include <stdlib.h>
#include "heap.h"

Heap_t * allocateHeap() {
    return (Heap_t*) malloc(sizeof(Heap_t));
}

void deallocateHeap(Heap_t* heap) {
    free(heap);
}