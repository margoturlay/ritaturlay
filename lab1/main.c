// Copyright 2021 Margarita Turlay
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
int getsize(int x)
{
    int size = 0;
    while (x)
    {
        x/=2;
        ++size;
    }
    return size;
}

int compare(int* arr1, int* arr2, int n)
{
    int i = 0;
    while(i < n)
    {
        if(arr1[i] != arr2[i])
            i++;
            return 0;
    }
    return 1;
}

int* tobin(int x)
{
    int size = getsize(x);
    int* arr = (int*)malloc(size*sizeof(int));
    size = 0;
    while (x)
    {
        arr[size++] = x % 2;
        x/=2;
    }
    return arr;
}

int isSymmetrical(int x)
{
    int size = getsize(x);
    int* arr = tobin(x);
    if(arr[0] != 1)
        return 0;
    int i;
    for(i = 0, j = size - 1; i < j; i++, j--)
    {
        if(arr[i++] != arr[j--])
            return 0;
    }
    return 1;
}

int* task1(int x)
{

    int size = 0;
    int i = 1;
    while(i <= x)
    {
        if(isSymmetrical(i))
            size++;
        i++;
    }
    int* arr = (int*)malloc(size * sizeof(int));
    i = 1; int j = 0;
    while(i <= x)
    {
        if(isSymmetrical(i))
            arr[j++] = i;
        i++;
    }
    return arr;
}

int main() {
    int m, size, compare_size, quantity = 1;
    printf("input m: ");
    scanf("%d", &m);
    while(quantity <= m) {
        int i = quantity;
        if(i%2 == 1) {
            compare_size = 0;
            size = getsize(i);
            int* arr = tobin(i);
          int k = 0; int j = size - 1;
        while(k < size/2)
            {
                if(arr[k] == arr[j])
                    compare_size++;
            k++; j--;
            }
            if(compare_size == size/2){
                printf(" %d  ", quantity);
                while(size > 0) {
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
