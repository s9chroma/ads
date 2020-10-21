typedef struct
{
  int *base;
  int front;
  int rear;
  int size;
  int capacity;
} queue_a;

queue_a *
create_queueA(int capacity);

int
queue_emptyA(queue_a *qu);

// This returns -1 if the queue is full
int
enqueueA(queue_a *qu, int item);

int
dequeueA(queue_a *qu);

int
front_elementA(queue_a *qu);

int
rear_elementA(queue_a *qu);

void
print_queueA(queue_a *qu);

void
obliterate_queueA(queue_a *qu);

