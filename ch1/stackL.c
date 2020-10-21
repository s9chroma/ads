#include <stdlib.h>
#include "stackL.h"

stack_l *
create_stackL()
{
  stack_l *st = (stack_l *) malloc(sizeof(stack_l));
  st -> next = NULL;
  return(st);
}

int
empty_stackL(stack_l *st)
{
  return(st -> next == NULL);
}

void
pushL(stack_l *st, int item)
{
  node_sl *new = (node_sl *) malloc(sizeof(node_sl));
  new -> item = item;
  new -> next = st -> next;
  st -> next = new;
}

int
popL(stack_l *st)
{
  node_sl *tmp = st -> next;
  int tmp_item = tmp -> item;
  st -> next = tmp -> next;
  free(tmp);
  return(tmp_item);
}

int
peekL(stack_l *st)
{
  return(st -> next -> item);
}

void
print_stackL(stack_l *st)
{
  printf("Printing Stack: \n");
  node_sl *tmp = st -> next;
  if(tmp == NULL)
  {
    printf("Empty stack\n");
  }
  else
  {
    while(tmp != NULL)
    {
      printf("--%d", tmp -> item);
      tmp = tmp -> next;
    }
    printf("\n");
  }
}

void
obliterate_stackL(stack_l *st)
{
  node_sl *tmp;
  do
  {
    tmp = st -> next;
    free(st);
    st = tmp;
  } while(tmp != NULL);
}
