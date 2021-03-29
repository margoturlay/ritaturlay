#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main() {  
    int str, col, i, j, a, var1, var2, var3, var4, x, z;

    printf("STRINGS = ");
    var1 = scanf("%d", &str);
    printf("COLUMNS = ");
    var2 = scanf("%d", &col);
      if ( (var1 || var2) != 1 ) {
        printf("INCORRECT INPUT"); 
        return 0;
    }

    int** arr = (int**)calloc(str, sizeof(*arr));
    for(z = 0; z < str; z++)
    arr[z] = (int*)calloc(col, sizeof(*arr[i]));

        
            while( i!=0 || j!=0 || x!=0) {
            printf("Индекс строки i = ");
            scanf("%d", &i);
            
             while((i > str-1) || i < 0) {
               printf("INCORRECT INPUT\nИндекс строки i = ");
               scanf("%d", &i);
            }
            printf("Индекс столбца j = ");
            scanf("%d", &j);
              
            while((j > col-1) || j < 0) {
               printf("INCORRECT INPUT\nИндекс столбца j = ");
               scanf("%d", &j);
            }
            printf("Значение элемента x = ");
            scanf("%d", &x);
            arr[i][j] = x;
        }

        for(int k = 0; k < str; k++) {
            for(int u = 0; u < col; u++) {
                if(arr[k][u] == 0)
                printf(" * ");
                else
                printf(" %d ", arr[k][u]);
            }
            printf("\n");
        }
}
