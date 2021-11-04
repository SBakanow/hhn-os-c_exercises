#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define CAPACITY 100

//Prototyp
int isEmpty();

/**
 * @brief Structure of the list stack
 * 
 */
typedef struct Stack
{
  struct Stack *previousEntry;
  int value;
} Stack_t;


//Create the global variables.
static Stack_t *topOfStack = NULL;
static int depthOfStack = 0;


/**
 * @brief Allocate new memory with the size of the stack structure.
 * 
 * @return Stack_t* The memory address of the new entry to the stack.
 */
Stack_t *createEntry()
{
  return (Stack_t *) malloc(sizeof(Stack_t));
}

/**
 * @brief Get the top of the stack and delete it.
 * 
 * @return int The value of the top of the stack or NULL if empty.
 */
int pop()
{
  if (isEmpty())
  {
    fprintf(stderr, "ERROR: Stack is empty, NULL return instead\n");
    return NULL;
  }

  Stack_t *bufferStack = topOfStack; //Save pointer on another pointer

  int buffer = bufferStack->value; //Buffer the variable from the top of the stack
  topOfStack = bufferStack->previousEntry; //Replace old entry with the previous entry

  free(bufferStack); //Free the adresse space

  depthOfStack--; //Reduce the depth

  return buffer;
}

/**
 * @brief Peek at the value at the top of the stack.
 * 
 * @return int Value of the top of the stack or NULL if empty
 */
int peek()
{
  if (isEmpty())
  {
    fprintf(stderr, "ERROR: Stack is empty, NULL return instead\n");
    return NULL;
  }
  return topOfStack->value;
}

/**
 * @brief Add a new value on top of the stack.
 * 
 * @param value The value that will be added at the top of the stack if there is still a space open.
 */
void push(int value)
{
  if (depthOfStack == CAPACITY) //Check if max capacity is already reached
  {
    fprintf(stderr, "ERROR: Size %d of stack exeeded when adding value %d\n", CAPACITY, value);
    return;
  }

  Stack_t *bufferStack = topOfStack; //Buffer the top of the stack
  topOfStack = createEntry(); //Get a new memory addresse for the new entry

  topOfStack->value = value; //Add the value on top of the stack
  topOfStack->previousEntry = bufferStack; //Save the old top of the stack into the previous entry of the stack.

  depthOfStack++; //Add one to the depth of the stack
}

/**
 * @brief Check if the stack is Empty.
 * 
 * @return int If the stack is empty it will negate the NULL and therfore send back an value not equal 0.
 */
int isEmpty()
{
  return !topOfStack;
}