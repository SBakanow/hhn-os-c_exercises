//
// Created by Marvin Simon on 10.11.21.
//
#include "freelist.h"

int main(int count, char *args[]) {
    insert(position(50), 50);
    insert(position(900), 900);
    free(0);
    insert(position(40), 40);
    insert(position(5), 5);
    insert(position(20), 20);
    insert(position(1), 1);
    insert(position(4), 4);
}
