#include <assert.h>
#include <stdio.h>
#include "main.h"

void test()
{
    char str2[5] = "Fgh h";

    assert(compare(str2) == 0);

    printf("All tests are passed.\n");
}
#undef main

int main() {
    test();
    return 0;
}
