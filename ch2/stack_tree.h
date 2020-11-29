#ifndef STACKTREE_H
#define STACKTREE_H

#include "search_tree.h"

typedef struct st_l
{
  tree_node *item;
  struct st_l *next;
} stack_tr_l, node_sl;

// first node is a placeholder
stack_tr_l *
create_stack_tree();

int
empty_stack_tree(stack_tr_l *st);

void
push_tree_stack(stack_tr_l *st, tree_node *item);

tree_node *
pop_tree_stack(stack_tr_l *st);

void
obliterate_tree_stack(stack_tr_l *st);

#endif
