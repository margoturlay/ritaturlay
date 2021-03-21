#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "main.h"
void TestFactorial() {
  assert(factorial(3) == 6);
  
}

#undef main

int main() {
    TestFactorial();
    printf("FACTORIAL TESTS ARE OK\n");
    return 0;
}
