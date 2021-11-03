#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct Stack {
  struct Stack *next;
  struct Stack *prev;
  int depth;
  int capacity;
  int value;
};

struct Stack* createStack()
{
  struct Stack* test = (struct Stack*) malloc(sizeof(struct Stack));

  return test;
}

struct Stack test;

int pop() {
  int buffer = test.value;
  test = *test.prev;
  free(test.next);
  return buffer;
} 

int peek() {
  return 0;
}

void push(int value) {
  if(test.depth < test.capacity) {
    test.next = (struct Stack*) malloc(sizeof(struct Stack));
    test.prev = &test;
    test = *test.next;
    test.depth++;
    test.capacity = 100;
    test.value = value;
  }
}


int main() {
  test = *(struct Stack*) malloc(sizeof(struct Stack));
  test.capacity = 100;
  test.depth = 0;
  push(2);
  push(3);
  printf("%d", pop());
  printf("%d", pop());
  return 0;
}