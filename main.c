//
// Created by Marvin Simon on 10.11.21.
//
#include <stdio.h>
#include "./aufgabe3/canonicalDevice.h"
#include <pthread.h>
#include <stdlib.h>


void call(void);

int main(int count, char *args[]) {
    pthread_t runDriver;

    emptymutex = sem_open("/empty", O_CREAT, 0644, DATA_LENGTH);
    if (emptymutex == SEM_FAILED) {
        perror("Failed to open semphore for empty");
        exit(-1);
    }

    fullmutex = sem_open("/full", O_CREAT, 0644, 0);
    if (fullmutex == SEM_FAILED) {
        perror("Failed to open semphore for full");
        exit(-1);
    }
    commandmutex = sem_open("/command", O_CREAT, 0644, 0);
    if (emptymutex == SEM_FAILED) {
        perror("Failed to open semphore for empty");
        exit(-1);
    }

    pthread_create(&runDriver, NULL, run, NULL);

    sem_close(fullmutex);
    sem_close(emptymutex);
    sem_close(commandmutex);

    call();

    closeDevice();
    pthread_join(runDriver, NULL);
    return 0;
}

void call(void) {
    for (int i = 0; i < 100000; ++i) {

    }
    for (int16_t i = 0; i < 512; ++i) {
        data[i % DATA_LENGTH] = i;
        if ((i+1)% DATA_LENGTH == 0 && i != 0) {
            while (command != idle || status == busy);
            command = write;
            while (command != idle || status == busy);
        }
    }
    while (command != idle || status == busy);
    command = write;

    while (command != idle || status == busy);
    command = read;
}
