#include <stdio.h>
#include "stackA.h"
#include "stackL.h"
#include "queueA.h"
#include "queueL.h"
#include "queueCL.h"

int
main(void)
{
  stack_l *st_l = create_stackL();
  stack_a *st_a = create_stackA(10);

  queue_a *qu_a = create_queueA(10);
  queue_l *qu_l = create_queueL();
  queue_cl *qu_cl = create_queueCL();

  //printf("Is stack empty?: %s \n", empty_stackA(st_a)? "True": "False");
  //printf("Is stack empty?: %s \n", empty_stackL(st_l)? "True": "False");
  //print_stackA(st_a);
  //print_stackL(st_l);

  //printf("Is queue empty?: %s\n", queue_emptyA(qu_a)? "True": "False");
  //printf("Is queue empty?: %s\n", queue_emptyL(qu_l)? "True": "False");
  printf("Is queue empty?: %s\n", queue_emptyCL(qu_cl)? "True": "False");

  print_queueL(qu_l);
  for(int i = 0;
      i < 10;
      i++)
  {
    //pushA(st_a, i);
    //print_stackA(st_a);
    //pushL(st_l, i);
    //print_stackL(st_l);

    //enqueueA(qu_a, i);
    //print_queueA(qu_a);

    //enqueueL(qu_l, i);
    //print_queueL(qu_l);

    enqueueCL(qu_cl, i);
    print_queueCL(qu_cl);
  }
  //printf("Is stack empty?: %s \n", empty_stackA(st_a)? "True": "False");
  //printf("Is stack empty?: %s \n", empty_stackL(st_l)? "True": "False");
  printf("Is queue empty?: %s\n", queue_emptyCL(qu_cl)? "True": "False");
  for(int i = 0; i < 5; i++)
  {
    //dequeueA(qu_a);
    //print_queueA(qu_a);

    //dequeueL(qu_l);
    //print_queueL(qu_l);

    dequeueCL(qu_cl);
    print_queueCL(qu_cl);
  }
  //printf("Is queue empty?: %s\n", queue_emptyL(qu_l)? "True": "False");
  printf("Is queue empty?: %s\n", queue_emptyCL(qu_cl)? "True": "False");
  for(int i = 0; i < 5; i++)
  {
    //enqueueA(qu_a, 30 + i);
    //print_queueA(qu_a);

    //enqueueL(qu_l, 30 + i);
    //print_queueL(qu_l);

    enqueueCL(qu_cl, 30 + i);
    print_queueCL(qu_cl);
  }

  //printf("Is queue empty?: %s\n", queue_emptyA(qu_a)? "True": "False");
  //printf("Is queue empty?: %s\n", queue_emptyL(qu_l)? "True": "False");
  printf("Is queue empty?: %s\n", queue_emptyCL(qu_cl)? "True": "False");
  for(int i = 0;
      i < 10;
      i++)
  {
    //printf("%d\n", peekL(st_l));
    //popA(st_a);
    //popL(st_l);
    //print_stackA(st_a);

    //dequeueA(qu_a);
    //print_queueA(qu_a);

    //dequeueL(qu_l);
    //print_queueL(qu_l);

    dequeueCL(qu_cl);
    print_queueCL(qu_cl);

    //printf("%d\n", rear_elementA(qu_a));
  }
  //printf("Is stack empty?: %s \n", empty_stackA(st_a)? "True": "False");
  //("Is stack empty?: %s \n", empty_stackL(st_l)? "True": "False");

  //printf("Is queue empty?: %s\n", queue_emptyA(qu_a)? "True": "False");
  //printf("Is queue empty?: %s\n", queue_emptyL(qu_l)? "True": "False");
  printf("Is queue empty?: %s\n", queue_emptyCL(qu_cl)? "True": "False");
}
