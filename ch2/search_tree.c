#include "search_tree.h"
#include <stdlib.h>

tree *
create_tree(void)
{
  tree *tmp = (tree *) malloc(sizeof(tree));
  tmp -> left = NULL;
  return(tmp);
}

void
left_rotation(tree_node *n)
{
  tree_node *tmp;
  int tmp_key;
  tmp = n -> left;
  tmp_key = n -> key;
  n -> left = n -> right;
  n -> key = n -> right -> key;
  n -> right = n -> left -> right;
  n -> left -> right = n -> left -> left;
  n -> left -> left = tmp;
  n -> left -> key = tmp_key;
}
