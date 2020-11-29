#include <stdlib.h>
#include "stack_tree.h"

stack_tr_l *
create_stack_tree()
{
  stack_tr_l *st = (stack_tr_l *) malloc(sizeof(stack_tr_l));
  st -> next = NULL;
  return(st);
}

int
empty_stack_tree(stack_tr_l *st)
{
  return(st -> next == NULL);
}

void
push_tree_stack(stack_tr_l *st, tree_node *item)
{
  node_sl *new = (node_sl *) malloc(sizeof(node_sl));
  new -> item = item;
  new -> next = st -> next;
  st -> next = new;
}

tree_node *
pop_tree_stack(stack_tr_l *st)
{
  node_sl *tmp = st -> next;
  tree_node *tmp_item = tmp -> item;
  st -> next = tmp -> next;
  free(tmp);
  return(tmp_item);
}

void
obliterate_tree_stack(stack_tr_l *st)
{
  node_sl *tmp;
  do
  {
    tmp = st -> next;
    free(st);
    st = tmp;
  } while(tmp != NULL);
}
