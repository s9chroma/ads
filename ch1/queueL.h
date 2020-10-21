#ifndef QUEUEL_H
#define QUEUEL_H

typedef struct nd
{
  int item;
  struct nd *next;
} node_ql;

typedef struct
{
  node_ql *front; // Dequeues at front
  node_ql *rear; // Enqueues at rear
  int size;
} queue_l;

queue_l *
create_queueL();

int
queue_emptyL(queue_l *qu);

void
enqueueL(queue_l *qu, int item);

int
dequeueL(queue_l *qu);

int
front_elementL(queue_l *qu);

int
rear_elementL(queue_l *qu);

void
print_queueL(queue_l *qu);

void
obliterate_queueL(queue_l *qu);

#endif
