#include "search_tree.h"
#include "stack_tree.h"
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

void
right_rotation(tree_node *n)
{
  tree_node *tmp;
  int tmp_key;
  tmp = n -> right;
  tmp_key = n -> key;
  n -> right = n -> left;
  n -> key = n -> left -> key;
  n -> left = n -> right -> left;
  n -> right -> left = n -> right -> right;
  n -> right -> right = tmp;
  n -> right -> key = tmp_key;
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
    return 0;
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
  if(root_node -> left == NULL) // empty
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

int *
delete(tree *root_node, int delete_key)
{
  tree_node *tmp_node, *parent_node, *other_node;
  int *deleted_object;

  if(root_node -> left == NULL) // tree is empty
  {
    return(NULL);
  }
  if(root_node -> right == NULL) // tree is leaf
  {
    if(root_node -> key == delete_key)
    {
      deleted_object = (int *) root_node -> left;
      root_node -> left = NULL;
      return(deleted_object);
    }
    else
    {
      return(NULL);
    }
  }
  else // traversing tree
  {
    tmp_node = root_node;
    while(tmp_node -> right != NULL) // until we reach a leaf
    {
      parent_node = tmp_node; // storing a pointer to parent node
      if(delete_key < tmp_node -> key)
      {
        tmp_node = parent_node -> left;
        other_node = parent_node -> right;
      }
      else
      {
        tmp_node = parent_node -> right;
        other_node = parent_node -> left;
      }
    }

    // reached leaf
    if(tmp_node -> key != delete_key)
    {
      return(NULL);
    }

    // reached leaf and found key

    parent_node -> key = other_node -> key;
    parent_node -> left = other_node -> left;
    parent_node -> right = other_node -> right;
    int *value_at_key = (int *)tmp_node -> left;
    free(tmp_node);
    free(other_node);
    return(value_at_key);
  }
}

tree_node *
interval_find(tree_node *tree, int key_start, int key_end)
{
  tree_node *tr_node;
  tree_node *tmp, *result_list;
  result_list = NULL;
  stack_tr_l *tree_stack = create_stack_tree();
  push_tree_stack(tree_stack, tree);
  while(!empty_stack_tree(tree_stack))
  {
    tr_node = pop_tree_stack(tree_stack);
    if(tr_node -> right == NULL)
    {
      /*reached leaf, now test*/
      tmp = (tree_node *) malloc(sizeof(tree_node));
      if(key_start <= tr_node -> key && tr_node -> key < b)
      {
        /*leaf key is in the interval given*/
        tmp -> key = tr_node -> key;
        tmp -> left = tr_node -> left;
        tmp -> right = result_list;
        result_list = tmp;
      }
    } /* not at the leaf yet, have to go down*/
    else if(key_end < tr_node -> key)
    {
      /*entire left interval*/
      push_tree_stack(tree_stack, tr_node -> left);
    }
    else if(tr_node -> key <= key_start)
    {
      /*entire right interval*/
      push_tree_stack(tree_stack, tr_node -> right);
    }
    else
    {
      /*node is in the interval, so push both left and right parts*/
      push_tree_stack(tree_stack, tr_node -> left);
      push_tree_stack(tree_stack, tr_node -> right);
    }
  }

  obliterate_tree_stack(tree_stack);
  return(result_list);
}
