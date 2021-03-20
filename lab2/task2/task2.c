#include <stdio.h>
#include <math.h>

int factorial (int n)
{
    return (n < 2) ? 1 : n * factorial (n - 1);
}


int main() {
    int n;
    float eps = 0.0000001, x, sum = 0;
    printf("x = ");
    scanf("%f",&x);

    for( n = 1; fabs(sin(x) - sum) >= eps; n++)
    {
      sum+= pow(-1,n - 1)*powf(x,2*n-1)/factorial(2*n-1);
    }

    printf("SUM = %f",sum);
    printf(" = sin(x) = %f\n", sin(x));
    printf("n = %d\n",n);
    return 0;
}
