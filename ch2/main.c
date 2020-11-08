#include <stdio.h>
#include "search_tree.h"
#include <time.h>
#include <stdlib.h>

#define NUM_VALUES 10000000

int
main(void)
{
  srand(time(NULL));
  int start = clock();

  tree *new_tree = create_tree();

  int insert_start_clock = clock();
  for(int i = 0;
      i < NUM_VALUES;
      i++)
  {
    int new_num = rand() % 100000;
    insert(new_tree, new_num, i);
  }
  int insert_end_clock = clock();
  printf("Time taken for insert: %f\n", ((double)(insert_end_clock - insert_start_clock)) / CLOCKS_PER_SEC);

  int find_start_clock = clock();
  for(int i = 0;
      i < NUM_VALUES;
      i++)
  {
    int search_key = rand() % 100000;
    find(new_tree, search_key);
  }
  int find_end_clock = clock();
  printf("Time taken for find iterative: %f\n", ((double)(find_end_clock - find_start_clock)) / CLOCKS_PER_SEC);

  int find_recur_start_clock = clock();
  for(int i = 0;
      i < NUM_VALUES;
      i++)
  {
    int search_key = rand() % 100000;
    find_recur(new_tree, search_key);
  }
  int find_recur_end_clock = clock();
  printf("Time taken for find recursive: %f\n", ((double)(find_recur_end_clock - find_recur_start_clock)) / CLOCKS_PER_SEC);

  int end = clock();
  printf("Complete time taken: %f\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}
