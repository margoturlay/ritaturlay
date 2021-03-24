#include <stdio.h>
#include <stdlib.h>
#include "main.h"
int getsize(int x)
{
    int size;
    size = 0;
    while (x)
    {
        x/=2;
        ++size;
    }
    return size;
}

int compare(int* arr1, int* arr2, int n)
{
    int i;
    i = 0;
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
    int size;
    size = getsize(x);
    int* arr;
    arr = (int*)malloc(size*sizeof(int));
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
    int size;
    size = getsize(x);
    int* arr;
    arr = tobin(x);
    if(arr[0] != 1)
        return 0;
    int i;
    i = 0; int j; j = size - 1;
    while(i < j)
    {
        if(arr[i++] != arr[j--])
            i++; j--;
            return 0;
    }
    return 1;
}

int* task1(int x)
{

    int size = 0;
    int i = 1, j = 0;
    int t; t = 1;
    while(i <= x)
    {
        if(isSymmetrical(i))
            size++;
        i++;
    }
    int* arr;
    arr = (int*)malloc(size * sizeof(int));
    while(i <= x)
    {
        if(isSymmetrical(t))
            arr[j++] = t;
        t++;
    }
    return arr;
}

int main() {
    int m, size, compare_size, quantity = 1, var;
    printf("input m: ");
    var = scanf("%d", &m);
    if (var != 1) 
     printf("INCORRECT INPUT! TRY AGAIN");  
    else{
    while(quantity <= m) {
        int i = quantity;
        if(i%2 == 1) {
            compare_size = 0;
            size = getsize(i);
            int* arr;
            arr = tobin(i);
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
    }
    

    return 0;
}
