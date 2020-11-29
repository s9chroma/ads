#include <stdio.h>
#include "search_tree.h"
#include <time.h>
#include <stdlib.h>

#define NUM_VALUES 10

#define NUMBER_WIDTH 4

#if 0
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
    int new_num = rand() % 100;
    insert(new_tree, new_num, i);
  }
  int insert_end_clock = clock();
  printf("Time taken for insert: %f\n", ((double)(insert_end_clock - insert_start_clock)) / CLOCKS_PER_SEC);

  tree_node *tmp = new_tree;
  int left_tree_size = 0;
  while(tmp -> right != NULL)
  {
    tmp = tmp -> left;
    left_tree_size++;
  }
  char *gap_string = "    ";
  tmp = new_tree;
  int tree_level = 0;
  while(tmp -> right != NULL)
  {
    for(int i = 0; i < (left_tree_size - tree_level); i++)
    {
      printf("%*c", NUMBER_WIDTH, ' ');
      printf("%s", gap_string);
    }
    printf("%d\n", tmp -> key);
    printf()
  }

  printf("%d\n", new_tree -> key);


  /*int find_start_clock = clock();
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
  printf("Complete time taken: %f\n", ((double)(end - start)) / CLOCKS_PER_SEC);*/
}
#endif

int
main(void)
{

}
