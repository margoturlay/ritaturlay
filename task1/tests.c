#include <assert.h>
#include <stdio.h>
#include "main.h"

void test()
{
    assert(strCmp("fghh","fghh") == 0);
    assert(Stringlen("jfdf") == 4);
    printf("All tests are passed.\n");
}
#undef main

int main() {
    test();
    return 0;
}
