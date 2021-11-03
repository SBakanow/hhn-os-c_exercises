#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int isEmpty();

struct Stack {
  struct Stack *next;
  int depth;
  int capacity;
  int value;
} Stack_default = {NULL, 0, 100, 0};

struct Stack* createEntry()
{
  struct Stack* test = (struct Stack*) malloc(sizeof(struct Stack));
  *test = Stack_default;

  return test;
}


struct Stack* test;
int depth;


int pop() {
  if(isEmpty())
  {
    fprintf(stderr, "ERROR: Stack is empty, NULL return instead");
    return NULL;
  }
  struct Stack* bufferStack = test;
  int buffer = test->value;
  test = test->next;
  free(bufferStack);
  return buffer;
  //return test->depth;
} 

int peek() {
  if(isEmpty()) {
    fprintf(stderr, "ERROR: Stack is empty, NULL return instead");
    return NULL;
  }
  return test->value;
}

void push(int value) {
  struct Stack* buffer = test;
  test = createEntry();
  if(buffer)
  {
    test->depth = buffer->depth;
    test->depth++;
    if(test->depth >= test->capacity) {
      test = buffer;
      fprintf(stderr, "ERROR: Size 100 of stack exeeded when adding value %d\n", value);
      return;
    }
  }
  test->next = buffer;
  test->value = value;
}

int isEmpty()
{
  return !test; //True if null
}


int main() {
  for(int i = 0; i < 110; i++) {
    push(i);
  }
  for(int i = 0; i < 100; i++) {
    printf("%d\n", peek());
    printf("%d\n", pop());
  }
  return 0;
}