#include <assert.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>
void test()
{
     assert(mycompare(arr1, str, col, arr2, str, col) == 0);
     printf("All tests are passed.\n");
}
#undef main

int main() {
    test();
    return 0;
}
