//
// Created by Marvin Simon on 08.01.22.
//

#ifndef HHN_C_CANOCICALDEVICE_H
#define HHN_C_CANOCICALDEVICE_H

#include <stdint.h>

#define DATA_LENGTH 20

typedef enum status_e{
    ready = 0,
    busy = 1,
    error = 2,
} status_e;

typedef enum command_e{
    idle = 0,
    read = 1,
    write = 2,
    reset = 4,
    delete = 8,
} command_e;


void* run(__attribute__((unused)) void* attr);
void disconnectDevice(void);


uint8_t status;
uint8_t command;
int8_t data[DATA_LENGTH];
#endif //HHN_C_CANOCICALDEVICE_H
