#include <stdio.h>

int
main(void)
{
  printf("\n");
}

void
left_rotation(tree_node *n)
{
  tree_node *tmp;
  int tmp_key;
  tmp = n -> left; // tmp = n.left
  tmp_key = n -> key; // tmp_key = n.key
  n -> left = n -> right; // n.left = n.right
  n -> key = n -> right -> key;
  n -> right = n -> left -> right;
  n -> left -> right = n -> left -> left;
  n -> left -> left = tmp;
  n -> left -> key = tmp_key;
}


