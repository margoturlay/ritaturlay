#include <assert.h>
void TestFactorial() {
  assert(factorial(3) == 6);
  
}

int main() {
    TestFactorial();
    printf("FACTORIAL TESTS ARE OK\n");
    return 0;