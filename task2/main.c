#include <stdio.h>
#include <math.h>
#include "main.h"

long int factorial(long int n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}


int main() {
    int n, var;
    float eps = 0.0000001, x, sum = 0;
    printf("x = ");
    var = scanf("%f", &x);
    if (var != 1) 
     printf("INCORRECT INPUT! TRY AGAIN");  
    else {
    for( n = 1; fabs(sin(x) - sum) >= eps; n++)
    {
      sum+= pow(-1,n - 1)*powf(x,2*n-1)/factorial(2*n-1);
    }

    printf("SUM = %f",sum);
    printf(" = sin(x) = %f\n", sin(x));
    printf("n = %d\n",n);
    }
    return 0;
}
