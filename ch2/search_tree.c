#include "search_tree.h"
#include <stdlib.h>

tree *
create_tree(void)
{
  tree *tmp = (tree *) malloc(sizeof(tree));
  tmp -> left = NULL;
  return(tmp);
}
