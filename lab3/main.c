#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main() {
    int str, col, i, j, a, var1, var2;
    printf("STRINGS = ");
    var1 = scanf("%d", str);
    printf("COLUMNS = ");
    var2 = scanf("%d", col);
    if((var1 || var2) != 1 ) {
    printf("INCORRECT INPUT");
    return 0;}

}