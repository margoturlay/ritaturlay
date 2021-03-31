#include <assert.h>
#include <stdio.h>
#include "main.h"

void test()
{

    char arr[3][3] = {'8', '*', '4',
                     '3', '*', '*',
                     '*', '*', '*' } ;       
    int arr1[3][3] =  { 8, 0, 4,
                        3, 0, 0,
                        0, 0, 0
                                };
    assert(compare(print_matrix(arr1, 3, 3), 3, 3, arr, 3, 3) == 0);

                                    
    printf("All tests are passed.\n");
}
#undef main

int main() {
    test();
    return 0;
}
