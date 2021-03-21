#include <assert.h>
#include <stdio.h>
#include "functions.h"

void test()
{
    assert(desyat(3, 4) == 0.8);
    printf("All tests are passed.\n");
}
#undef main

int main() {
    test();
    return 0;
}
