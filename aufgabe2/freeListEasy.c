//
// Created by Marvin Simon on 23.11.21.
//

#include <stdbool.h>
#include <stdio.h>
#include "freeListEasy.h"


#define MAIN_MEMORY 1000

static int restMemory = MAIN_MEMORY;

typedef struct FreeList {
    int reservedMemory;
    bool reserved;
}FreeList_t;

static FreeList_t freeListMemory [MAIN_MEMORY] = {0, false};

int position(int size) {
    for(int i = 0; i < MAIN_MEMORY; i++) {
        if(restMemory < size) {
            return -1;
        }
        if(!freeListMemory[i].reserved
        && (freeListMemory[i].reservedMemory >= size || freeListMemory[i].reservedMemory == 0)) {
            return i;
        }
    }
    return -1;
}

void insert(int position, int size) {

    if(!freeListMemory[position].reserved
    && (freeListMemory[position].reservedMemory == size || freeListMemory[position].reservedMemory == 0)
    && restMemory >= size)
    {
        freeListMemory[position].reserved = true;
        freeListMemory[position].reservedMemory = size;
        restMemory -= size;
    } else {
        for (int i = 0; i < MAIN_MEMORY; i++) {
            if (!freeListMemory[i].reserved
                && (freeListMemory[i].reservedMemory >= size)
                && restMemory >= size) {
                freeListMemory[i].reserved = true;
                if (freeListMemory[i].reservedMemory != 0 && freeListMemory[i].reservedMemory != size) {
                    FreeList_t buffer = freeListMemory[i + 1];
                    freeListMemory[i + 1].reservedMemory = freeListMemory[i].reservedMemory - size;
                    freeListMemory[i].reservedMemory = size;
                    restMemory -= size;
                    freeListMemory[i + 1].reserved = false;
                    for (int j = i + 2; j < MAIN_MEMORY; j++) {
                        FreeList_t buffer2 = freeListMemory[j];
                        freeListMemory[j] = buffer;
                        buffer = buffer2;
                    }
                }
                break;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < MAIN_MEMORY; ++i) {
        if(freeListMemory[i].reserved) {
            printf("Position %d, Size %d -> ", i, freeListMemory[i].reservedMemory);
        }
    }
}
void free(int position) {
    if(position < MAIN_MEMORY) {
        freeListMemory[position].reserved = false;
        restMemory += freeListMemory[position].reservedMemory;
    }

    printf("\n");

    for (int i = 0; i < MAIN_MEMORY; ++i) {
        if(freeListMemory[i].reserved) {
            printf("Position %d, Size %d -> ", i, freeListMemory[i].reservedMemory);
        }
    }
}