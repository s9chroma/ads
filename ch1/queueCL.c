#include <stdlib.h>
#include "queueCL.h"

queue_cl *
create_queueCL()
{
  node_cl *entrypoint = (node_cl *) malloc(sizeof(node_cl));
  node_cl *placeholder = (node_cl *) malloc(sizeof(node_cl));
  entrypoint -> next = placeholder;
  placeholder -> next = placeholder;
  entrypoint -> item = 0; // size of queue
  return(entrypoint);
}

int
queue_emptyCL(queue_cl *qu)
{
  return(qu -> item == 0);
}

void
enqueueCL(queue_cl *qu, int item)
{
  node_cl *new = (node_cl *) malloc(sizeof(node_cl));
  new -> item = item;
  node_cl *tmp = qu -> next;
  new -> next = tmp -> next;
  tmp -> next = new;
  qu -> next = new;
  qu -> item++; //incrementing size
}

int
dequeueCL(queue_cl *qu)
{
  queue_cl *tmp;
  int tmp_item;
  tmp = qu -> next -> next -> next; //front of the queue
  qu -> next -> next -> next = tmp -> next;
  if(tmp == qu -> next)
    qu -> next = tmp -> next;
  tmp_item = tmp -> item;
  free(tmp);
  qu -> item--; //decrementing size
  return(tmp_item);
}

int
front_elementCL(queue_cl *qu)
{
  return(qu -> next -> next -> next -> item);
}

int
rear_elementCL(queue_cl *qu)
{
  return(qu -> next -> item);
}

void
print_queueCL(queue_cl *qu)
{
  printf("Printing Queue: \n");
  if(qu -> item == 0) // size 0
    printf("Empty Queue");

  node_cl *tmp = qu -> next -> next -> next;
  for(int i = 0;
      i < qu -> item;
      i++)
  {
    printf("--%d", tmp -> item);
    tmp = tmp -> next;
  }
  printf("\n");
}


