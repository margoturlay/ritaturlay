#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void print_menu() {
 printf("Menu\n");
printf("1.Ввести числитель и знаменатель \n");
printf("2.Вывод числа \n");
printf("3.Вывод обратного числа \n");
printf("4.Вывод сокращенного числа \n");
printf("5.Информация о версии и авторе \n");
printf("6.Выход \n");
printf("Enter your choice :  ");
}

void get_version() { printf("v. 1.0.0\n© Margarita Turlay, 2021\n"); }

int sokrat(int a, int b) {
      int j, less;                                 
        if (a < b)                               
            less = a;                               
          else                                                   
            less = b;                               
          for (j = less; j > 0; j--)  {                     
            if (!((int)a% j) && !((int)b % j)) {     
               a/= j;                         
               b /= j; }                        
}
           return a;  
}
 float desyat(int a, int b) {
          float t = (float)a / (float)b;
          return t;
        }


int main() {
int numerator, denominator;
int choice;
do {
print_menu();
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
        float z = desyat(numerator, denominator);
        printf("Дробь \nДесятичный вид:%2.1f", z);
        printf("\nНаучный вид:%.2E\n\n",(float)numerator / (float)denominator);
        break;
    }
    case 3: {
        printf("\nОбратное число:%d/%d\n\n", denominator, numerator);
        break;
    }
    case 4: {
int j, less;                               
do{
    if(numerator < denominator)                                 
        less = numerator;                            
    else                                                  
        less = denominator;                                
    for(j = less; j > 0; j--){                    
        if(!(numerator % j) && !(denominator % j)){     
            numerator/= j;                   
            denominator /= j;                          
            break;                              
        }
    }
}while(j != 1);                                   
          printf("\nСокращенное число:%d/%d\n\n", numerator, denominator);
          break;
    }
    case 5: {
       get_version();
        break;
    }
    case 6: {
        printf("Goodbye\n");
        break;
    }
}
}
while (choice != 6);
return 0;
}
