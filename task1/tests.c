#include <assert.h>
#include <stdio.h>
#include "main.h"

void test()
{
    assert(lower("FGHH") == "fghh");

    printf("All tests are passed.\n");
}
#undef main

int main() {
    test();
    return 0;
}
