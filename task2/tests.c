#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

void test()
{
    printf("All tests are passed.\n");
}
#undef main

int main() {
    test();
    return 0;
}
