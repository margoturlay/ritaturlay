#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "main.h"
void TestFactorial() {
  assert(factorial(3) == 6);
  assert(factorial(1) == 1);
  assert(factorial(2) == 2);
  assert(factorial(4) == 24);
}

#undef main

int main() {
    TestFactorial();
    printf("FACTORIAL TESTS ARE OK\n");
    return 0;
}
