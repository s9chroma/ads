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
  if(root_node -> left == NULL)
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
  if((root_node -> right == NULL && root_node -> key != query_key) || (root_node -> left == NULL))
  {
    return(NULL);
  }
  // if i reached a leaf and value matches return the value on left
  else if(root_node -> right == NULL & root_node -> key == query_key)
  {
    return ((int *) root_node -> left);
  }
  // otherwise descend tree recursively
  else
  {
    if(query_key < root_node -> key)
    {
      return find_recur(root_node -> left, query_key);
    }
    else
    {
      return find_recur(root_node -> right, query_key);
    }
  }
}

int
insert(tree *root_node, int new_key, int new_object)
{
  if(root_node -> left == NULL)
  {
    root_node -> left = (tree_node *) new_object;
    root_node -> key = new_key;
    root_node -> right = NULL;
  }
  else
  {
    tree_node *tmp;
    tmp = root_node;
    while(tmp -> right != NULL) // while im not at a leaf yet
    {
      if(new_key < tmp -> key)
      {
        tmp = tmp -> left;
      }
      else
      {
        tmp = tmp -> right;
      }
    }

    if(tmp -> key == new_key)
    {
      return(-1);
    }

    // key is distinct and we found the insert location, now performing insert

    tree_node *old_leaf, *new_leaf;

    old_leaf = (tree_node *) malloc(sizeof(tree_node));
    old_leaf -> left = tmp -> left;
    old_leaf -> key = tmp -> key;
    old_leaf -> right = NULL;

    new_leaf = (tree_node *) malloc(sizeof(tree_node));
    new_leaf -> left = (tree_node *) new_object;
    new_leaf -> key = new_key;
    new_leaf -> right = NULL;

    if(tmp -> key < new_key)
    {
      tmp -> left = old_leaf;
      tmp -> right = new_leaf;
      tmp -> key = new_key;
    }
    else
    {
      tmp -> left = new_leaf;
      tmp -> right = old_leaf;
    }
  }

  return(0);
}
