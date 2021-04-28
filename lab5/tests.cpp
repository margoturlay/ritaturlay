#include "main.h"
#include <iostream>                         
#include <cassert>                           
 
void test()
{
  char s1[32];
  assert(dec_to_oct(s1, 7000));
  std::cout << "ALL TESTS ARE PASSED ";
}
 
int main()
{
  test();

  return 0;
}