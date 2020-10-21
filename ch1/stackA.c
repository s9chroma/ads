#include "stackA.h"
#include <stdlib.h>

stack_a *
create_stackA(int size)
{
  stack_a *st = (stack_a *) malloc(sizeof(stack_a));
  st -> base = (int *) malloc(sizeof(int));
  st -> top = st -> base;
  st -> size = size;
  return(st);
}

int
empty_stackA(stack_a *st)
{
  return(st -> base == st -> top);
}

int
pushA(stack_a *st, int item)
{
  if(st -> top < st -> base + st -> size)
  {
    *(st -> top++) = item;
    return(0);
  }
  else
  {
    return(-1);
  }
}

int
popA(stack_a *st)
{
  st -> top--;
  return(*(st -> top));
}

int
peekA(stack_a *st)
{
  return(*(st -> top - 1));
}

void
print_stackA(stack_a *st)
{
  printf("Printing Stack: \n");
  if(st -> base != st -> top)
  {
    for(int *tmp = st -> top - 1;
        tmp >= st -> base;
        tmp--)
    {
      printf("--%d", *(tmp));
    }
    printf("\n");
  }
  else
  {
    printf("Empty stack\n");
  }
}

void
obliterate_stackA(stack_a *st)
{
  free(st -> base);
  free(st);
}
