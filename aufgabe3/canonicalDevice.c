//
// Created by Marvin Simon on 08.01.22.
//
#include <stdint.h>
#include <stdio.h>
#include "canonicalDevice.h"

#define MAX_MEMORY 1024

void readData(void);
void resetData(void);
void deleteData(void);
void writeData(void);

static int16_t internalMemory[MAX_MEMORY];
static int16_t internalPointer = 0;
uint8_t flag = 1;

void *run(__attribute__((unused)) void *attr) {
    status = ready;
    for (int i = 0; i < MAX_MEMORY; ++i) {
        internalMemory[i] = 0;
    }
    while (flag) {
        command = idle;
        while (command == idle);
        switch (command) {
            case read:
                readData();
                break;
            case reset:
                resetData();
                break;
            case delete:
                deleteData();
                break;
            case idle:
                break;
            case write:
                writeData();
                break;
            default:
                printf("Invalid Command");
                break;
        }
    }
    return NULL;
}

void resetData() {
    status = busy;
    internalPointer = 0;
    status = ready;
}

void deleteData() {
    status = busy;
    for (int i = 0; i < MAX_MEMORY; ++i) {
        internalMemory[i] = 0;
    }
    status = ready;
}

void readData() {
    status = busy;
    printf("Reading memory data: ");
    for (int i = 0; i < internalPointer; ++i) {
        printf("%d ", internalMemory[i]);
    }
    printf("\n");
    printf("Pointer length: %d\n", internalPointer);
    internalPointer = 0;
    status = ready;
}

void writeData() {
    status = busy;
    for (int i = 0; i < DATA_LENGTH; ++i) {
        if (internalPointer == MAX_MEMORY) {
            status = error;
            return;
        }
        internalMemory[internalPointer] = data[i];
        internalPointer++;
        data[i] = 0;
    }
    status = ready;
}

void disconnectDevice(void) {
    while (command != idle || status == busy);
    flag = 0;
    command = reset;
}