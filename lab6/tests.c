#include <assert.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>
typedef struct item {
  int data;
  struct item *left;
  struct item *right;
} Item;
 
void AddNode(int data, Item **node);
int get(Item * node,int n,int c);
void lvl(Item * root);
 
 

void test()
{
  char buffer[512];
  int i;
  Item *root = NULL; 
  FILE *fp = fopen("ex52.txt", "r"); 
 
  if (!fp) exit(1); 
  
  while (fgets(buffer, 512, fp) != NULL)
    AddNode(atoi(buffer), &root); 
  lvl(root);
  fclose(fp);  
  int t = 0, l = 0;
  assert(get(root, t, 0) == 0));
     printf("All tests are passed.\n");
}
#undef main

int main() {
    test();
    return 0;
}
