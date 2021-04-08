#include <assert.h>
#include <stdio.h>
#include "main.h"

void test()
{
    assert(Stringlen("jfdf") == 4);
    assert(Stringlen("sunday") == 6);
    printf("All tests are passed.\n");
}
#undef main

int main() {
    test();
    return 0;
}
