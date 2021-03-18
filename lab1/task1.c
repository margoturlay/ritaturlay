// Copyright 2021 Margarita Turlay
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    int m, size;
    int compare_size;
    int quantity = 1;
    printf("Input m: ");
    scanf(" %d", &m);
    while (quantity <= m) {
        int i = quantity;
        if (i%2 == 1) {
            size = 0;
            compare_size = 0;
            int* arr = (int*)malloc((size+1)*sizeof(int));
            while (i) {
                arr[size] = i%2;
                i/=2;
                size++;
            }
            for (int k = 0, j = size - 1; k < size/2; k++, j--) {
                if(arr[k] == arr[j])
                    compare_size++;
            }
            if (compare_size == size/2) {
                printf(" %d   ", quantity);
                while (size > 0) {
                    printf(" %d", arr[size-1]);
                    size--;
                }
                printf("\n");
            }
        }
        quantity++;
    }
    return 0;
}
