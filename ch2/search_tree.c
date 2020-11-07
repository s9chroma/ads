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

int *
find(tree *root_node, int query_key)
{
  tree_node *tmp;
  if(tree -> left == NULL)
  {
    return(NULL);
  }

  tmp = root_node;
  while(tmp -> right != NULL)
  {
    if(query_key < tmp -> key)
    {
      tmp = tmp -> left;
    }
    else
    {
      tmp = tmp -> right;
    }
  }

  if(tmp -> key == query_key)
  {
    return (int *)(tmp -> left);
  }
  else
  {
    return(NULL);
  }
}

int *
find_recur(tree *root_node, int query_key)
{
  // if (i reached a leaf and value doesnt match) or (im in an empty tree)
  if((tree -> right == NULL && tree -> key != query) || (tree -> left == NULL))
  {
    return(NULL);
  }
  // if i reached a leaf and value matches return the value on left
  else if(tree -> right == NULL & tree -> key == query_key)
  {
    return ((int *) tree -> left);
  }
  // otherwise descend tree recursively
  else
  {
    if(query_key < tree -> key)
    {
      return find_recur(tree -> left, query_key);
    }
    else
    {
      return find_recur(tree -> right, query_key);
    }
  }
}
