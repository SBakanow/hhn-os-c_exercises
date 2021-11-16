#include <stdbool.h>
#include "freeList.h"

#define MAIN_MEMORY 1000

typedef struct FreeList
{
    int sizeOfMemory;
    bool reserved;
} FreeList;

static FreeList freeList[MAIN_MEMORY] = {false};

int position(int size) {
    for(int i = 0; i < MAIN_MEMORY; i++) {
        freeList[i].sizeOfMemory
    }
    return 0;
}

void insert(int position, int size) {
}

void free(int position){

}