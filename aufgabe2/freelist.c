#include <stdbool.h>
#include <stdio.h>
#include "freelist.h"


#define MAIN_MEMORY 1000

void initTheArray();
static int restMemory = MAIN_MEMORY;

typedef struct FreeList {
    int reservedMemory;
    int location;
    bool reserved;
}FreeList_t;

bool initArray = false;
static FreeList_t freeListMemory [MAIN_MEMORY] = {0, -1, false};

int position(int size) {
    initTheArray();
    int openSpace = 0;
    if(restMemory < size) {
        return -1;
    }
    for (int i = 0; i < MAIN_MEMORY; i++) {
        if(!freeListMemory[i].reserved) {
            openSpace++;
            if(openSpace == size) {
                return i - openSpace + 1;
            }
        } else {
            openSpace = 0;
        }
    }
    return -1;
}

void insert(int position, int size) {
    initTheArray();
    if(restMemory < size) {
        return;
    }
    int openSpace = 0;
    for (int i = position; i < position+size; i++) {
        if(!freeListMemory[i].reserved) {
            openSpace++;
            if(openSpace == size) {
                break;
            }
        } else {
            openSpace = 0;
        }
    }
    if(openSpace == size) {
        freeListMemory[position].location = position;
        freeListMemory[position].reservedMemory = size;
        restMemory -= size;
        for(int i = position; i < position+size; i++) {
            freeListMemory[i].reserved = true;
        }
    }

    printf("\n");
    for (int i = 0; i < MAIN_MEMORY; ++i) {
        if(freeListMemory[i].reservedMemory != 0) {
            printf("Position %d, Size %d -> ", i, freeListMemory[i].reservedMemory);
        }
    }
}
void free(int position) {
    initTheArray();
    if(freeListMemory[position].location == position) {
        for (int i = position; i < position+freeListMemory[position].reservedMemory; ++i) {
            freeListMemory[i].reserved = false;
        }
        freeListMemory[position].location = 0;
        freeListMemory[position].reservedMemory = 0;
    }

    printf("\n");

    for (int i = 0; i < MAIN_MEMORY; ++i) {
        if(freeListMemory[i].reservedMemory != 0) {
            printf("Position %d, Size %d -> ", i, freeListMemory[i].reservedMemory);
        }
    }
}

void initTheArray() {
    if(!initArray) {
        for (int i = 0; i < MAIN_MEMORY; ++i) {
            freeListMemory[i].reservedMemory = 0;
            freeListMemory[i].location = -1;
            freeListMemory[i].reserved = false;
        }
    }
    initArray = true;
}