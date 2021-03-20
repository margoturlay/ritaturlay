// Copyright 2021 Margarita Turlay
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int numerator, denominator;
int choice;
int main() {
do {
menu();
scanf("%d", &choice);
switch (choice) {
    case 1: {
        printf("Числитель = ");
        scanf("%d", &numerator);
        printf("Знаменатель = ");
        scanf("%d", &denominator);
        break;
    }
    case 2: {
        printf("Дробь \nДесятичный вид:%2.1f", (float)numerator / (float)denominator);
        printf("\nНаучный вид:%.2E\n\n",(float)numerator / (float)denominator);
        break;
    }
    case 3: {
        printf("\nОбратное число:%d/%d\n\n", denominator, numerator);
        break;
    }
    case 4: {
        int j, less;                                 
        do 
        {
          if (numerator < denominator)                               
            less = numerator;                               
          else                                                   
            less = denominator;                               
          for (j = less; j > 0; j--)  {                     
            if (!((int)numerator % j) && !((int)denominator % j)) {     
               numerator/= j;                         
               denominator /= j;                          
               break;                               
            }
          }
        }
        while (j != 1);  
          printf("\nСокращенное число:%d/%d\n\n", numerator, denominator);
          break;
    }
    case 5: {
        printf("Автор: Турлай Маргарита \nВерсия: 1\n\n");
        break;
    }
    case 6: {
        printf("Goodbye\n");
        break;
    }
    default: {
        printf("Wrong Choice. Enter again\n");
        continue;
    }
}
}
while (choice != 6);
return 0;
}
