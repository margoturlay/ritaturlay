#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "functions.h"
void TestFactorial() {
  assert(factoriall(3) == 6);
  
}

int main() {
    TestFactorial();
    printf("FACTORIAL TESTS ARE OK\n");
    return 0;
}
