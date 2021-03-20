#include <assert.h>
#include <stdio.h>
#include "main.h"

void test()
{
    assert(getsize(1) == 1);
    assert(getsize(3) == 2);
    assert(getsize(11) == 4);
    assert(getsize(15) == 4);
    printf("All tests are passed.\n");
}
#undef main

int main() {
    test();
    return 0;
}
