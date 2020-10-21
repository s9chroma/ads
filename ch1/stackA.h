#ifndef STACKA_H
#define STACKA_H

typedef struct
{
  int *base;
  int *top;
  int size; // size of the array
} stack_a;

stack_a *
create_stackA(int size);

int
empty_stackA(stack_a *st);

int // return value signifies if push is successful or not
pushA(stack_a *st, int item);

int
popA(stack_a *st);

int
peekA(stack_a *st);

void
print_stackA(stack_a *st);

void
obliterate_stackA(stack_a *st);

#endif
