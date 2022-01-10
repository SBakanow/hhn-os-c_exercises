//
// Created by Marvin Simon on 10.11.21.
//
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "./aufgabe3/canonicalDevice.h"


void call(void);
void writeRandomData(uint16_t byteCount);
void resetDevice(void);

int main(int count, char *args[]) {
    pthread_t runDriver;
    pthread_create(&runDriver, NULL, run, NULL);

    call();

    disconnectDevice();
    pthread_join(runDriver, NULL);
    return 0;
}

void call(void) {
    for (int i = 0; i < 100000; ++i) {
        //Block until thread begins work
    }

    writeRandomData(512);
    while (command != idle || status == busy);
    command = read;

    resetDevice();
    writeRandomData(2048);
    while (command != idle || status == busy);
    command = read;

    resetDevice();
    writeRandomData(256);
    while (command != idle || status == busy);
    command = read;

}

void resetDevice(void) {
    while (command != idle || status == busy);
    command = delete;

    while (command != idle || status == busy);
    command = reset;
}


void writeRandomData(uint16_t byteCount) {
    for (uint16_t i = 0; i < byteCount; ++i) {
        //data[i % DATA_LENGTH] = i % (UINT8_MAX + 1);
        data[i % DATA_LENGTH] = rand() % (UINT8_MAX + 1);
        if ((i + 1) % DATA_LENGTH == 0 && i != 0) {
            while (command != idle || status == busy);
            command = write;
            while (command != idle || status == busy);
        }
    }

    if (byteCount % 20 != 0) {
        while (command != idle || status == busy);
        command = write;
    }
}