#include <assert.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>
void test()
{
    int z, k;
    int str, col;
    int** arr1;
    int** arr2;
    arr1 = (int**)calloc(str, sizeof(*arr1));
    for (z = 0; z < str; z++)
    arr1[z] = (int*)calloc(col, sizeof(*arr1[z]));
    if(!arr1)
        printf("Incorrect value\n");
    arr2 = (int**)calloc(str, sizeof(*arr2));
    for (k = 0; k < str; k++)
    arr2[k] = (int*)calloc(col, sizeof(*arr2[k]));
    if(!arr2)
        printf("Incorrect value\n");

    assert(mycompare(arr1, str, col, arr2, str, col) == 0);
    printf("All tests are passed.\n");
}
#undef main

int main() {
    test();
    return 0;
}
