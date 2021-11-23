#include <stdbool.h>
#include "freeList.h"
#include "heap.h"

#define MAIN_MEMORY 1000

void initHeap();


int position(int size) {

}

void insert(int position, int size) {
    initHeap();
    Heap_t* heapBuffer = heapMemory;
    if(heapBuffer->memory >= size) {
        while (heapBuffer->position != -1) {
            if(heapBuffer->position == position){
                return;
            }
            heapBuffer = heapBuffer->previousEntry;
        }
    }
    //Allocate new Heap
    heapMemory->nextEntry = allocateHeap();
    //Save the complete unused memory on the head
    heapMemory->nextEntry->memory = heapMemory->memory - size;
    //Set the position
    heapMemory->position = position;
    heapMemory->memory = size;
    heapMemory->nextEntry->previousEntry = heapMemory;
    heapMemory = heapMemory->nextEntry;
    heapMemory->memory -= heapMemory->previousEntry->memory;

}

void free(int position){

}

void initHeap() {
    if(heapMemory == NULL) {
        heapMemory = allocateHeap();
        heapMemory->memory = MAIN_MEMORY;
        heapMemory->position = -1;
    }
}