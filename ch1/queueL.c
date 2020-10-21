#include <stdlib.h>
#include "queueL.h"

queue_l *
create_queueL()
{
  queue_l *qu = (queue_l *) malloc(sizeof(queue_l));
  qu -> front = NULL;
  qu -> rear = NULL;
  qu -> size = 0;
  return(qu);
}

int
queue_emptyL(queue_l *qu)
{
  return(qu -> size == 0);
}

void
enqueueL(queue_l *qu, int item)
{
  node_ql *new = (node_ql *) malloc(sizeof(node_ql));
  new -> item = item;
  new -> next = NULL;
  if(qu -> size != 0)
  {
    qu -> rear -> next = new;
    qu -> rear = new;
  }
  else
  {
    qu -> front = qu -> rear = new;
  }
  qu -> size++;
}

int
dequeueL(queue_l *qu)
{
  node_ql *tmp = qu -> front;
  int tmp_item = tmp -> item;
  qu -> front = qu -> front -> next;
  qu -> size--;
  if(qu -> size == 0)
  {
    qu -> rear = NULL;
  }
  free(tmp);
  return(tmp_item);
}

void
print_queueL(queue_l *qu)
{
  printf("Printing Queue: \n");
  if(qu -> size == 0)
  {
    printf("Empty Queue");
  }
  node_ql *tmp = qu -> front;
  while(tmp != NULL)
  {
    printf("--%d", tmp -> item);
    tmp = tmp -> next;
  }
  printf("\n");
}

int
front_elementL(queue_l *qu)
{
  return(qu -> front -> item);
}

int
rear_elementL(queue_l *qu)
{
  return(qu -> rear -> item);
}

void
obliterate_queueL(queue_l *qu)
{
  node_ql *tmp = qu -> front;
  while(tmp != NULL)
  {
     node_ql *next = tmp -> next;
     free(tmp);
     tmp = next;
  }
  free(qu);
}
