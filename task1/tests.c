#include <assert.h>
#include <stdio.h>
#include "functions.h"

void test()
{
    assert(sokrat(3, 9) == 1);
    printf("All tests are passed!\n");
}
#undef main

int main() {
    test();
    return 0;
}
