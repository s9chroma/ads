#ifndef QUEUECL_H
#define QUEUECL_H

typedef struct nd_cl
{
  int item; // for entrypoint this field holds size
  struct nd_cl *next;
} node_cl, queue_cl;

// This returns entrypoint
queue_cl *
create_queueCL();

int
queue_emptyCL(queue_cl *qu);

void
enqueueCL(queue_cl *qu, int item);

int
dequeueCL(queue_cl *qu);

int
front_elementCL(queue_cl *qu);

int
rear_elementCL(queue_cl *qu);

void
print_queueCL(queue_cl *qu);

void
obliterate_queueCL(queue_cl *qu);

#endif
