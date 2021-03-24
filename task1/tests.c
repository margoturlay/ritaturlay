#include <assert.h>
#include <stdio.h>
#include "functions.h"

void test()
{
    assert(sokrat(3, 9) == 1);
    assert(sokrat(4, 10) == 2);
    assert(sokrat(12, 32) == 3);
    assert(sokrat(20, 24) == 5);
    printf("All tests are passed!\n");
}
#undef main

int main() {
    test();
    return 0;
}
