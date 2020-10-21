#include <stdlib.h>
#include "queueA.h"

queue_a *
create_queueA(int capacity)
{
  queue_a *qu = (queue_a *) malloc(sizeof(queue_a));
  qu -> base = (int *) malloc(capacity * sizeof(int));
  qu -> front = 0;
  qu -> rear = 0;
  qu -> size = 0;
  qu -> capacity = capacity;

  return(qu);
}

int
queue_emptyA(queue_a *qu)
{
  return(qu -> size == 0);
}

int
enqueueA(queue_a *qu, int item)
{
  if(qu -> size != qu -> capacity)
  {
    *(qu -> base + qu -> rear) = item;
    qu -> size++;
    qu -> rear = (qu -> rear + 1) % (qu -> capacity);
    return(0);
  }
  else
  {
    return(-1);
  }
}

int
dequeueA(queue_a *qu)
{
  int tmp_item = *(qu -> base + qu -> front);
  qu -> front = (qu -> front + 1) % (qu -> capacity);
  qu -> size--;
  return(tmp_item);
}

void
print_queueA(queue_a *qu)
{
  printf("Printing Queue: \n");
  if(qu -> size == 0)
  {
    printf("Empty Queue");
  }
  for(int i = 0;
      i < qu -> size;
      i++)
  {
    int current_index = (qu -> front + i) % (qu -> capacity);
    printf("--%d", *(qu -> base + current_index));
  }
  printf("\n");
}

int
front_elementA(queue_a *qu)
{
  return(*(qu -> base + qu -> front));
}

int
rear_elementA(queue_a *qu)
{
  return(*(qu -> base + qu -> rear - 1));
}

void
obliterate_queueA(queue_a *qu)
{
  free(qu -> base);
  free(qu);
}
