#ifndef HHN_C_FREELIST_H
#define HHN_C_FREELIST_H

int position(int size);
void insert(int position, int size);
void free(int position);

#endif //HHN_C_FREELIST_H
