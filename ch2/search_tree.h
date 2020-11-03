#ifndef SEARCHTREE_H
#define SEARCHTREE_H

typedef struct tr_n
{
  int key;
  struct tr_n *left;
  struct tr_n *right;
} tree_node, tree;

tree *
create_tree(void);

void
left_rotation(tree_node *n);

void
right_rotation(tree_node *n);

#endif
