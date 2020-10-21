#ifndef STACKL_H
#define STACKL_H

typedef struct st_l
{
  int item;
  struct st_l *next;
} stack_l, node_sl;

// first node is a placeholder
stack_l *
create_stackL();

int
empty_stackL(stack_l *st);

void
pushL(stack_l *st, int item);

int
popL(stack_l *st);

int
peekL(stack_l *st);

void
print_stackL(stack_l *st);

void
obliterate_stackL(stack_l *st);

#endif
