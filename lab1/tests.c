#include <assert.h>
#include <stdio.h>
#include "main.h"

void test()
{
    assert(getsize(1) == 1);
    printf("All tests are passed.\n");
}
#undef main

int main() {
    test();
    return 0;
}
