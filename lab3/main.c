#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void print_menu() {
  printf("2 - вывод матрицы \n");
  printf("3 - Дозаполнить матрицу или изменить значения\n");
  printf("0 - закончить работу \n");
  printf("Ваш выбор: ");
}

void print_menu2() {
  printf("Что вы хотите?\n");
  printf("1 - изменить значение \n");
  printf("2 - оставить старое значение \n");
  printf("Ваш выбор: ");
}

int mycompare(int **arr1, int str1, int col1, int **arr2, int str2, int col2) {
  int i, j;
  if (str1 != str2 || col1 != col2)
    return 1;
  for (i = 0; i < str1; i++)
    for (j = 0; j < col1; j++)
      if (arr1[i][j] != arr2[i][j])
        return 1;
  return 0;
}

int main() {
  int str, col, i, j, x, z, choice, choice2;
  int var, var1, var2, var3, var4, var5;
  int **arr;
  printf("STRINGS = ");
  var1 = scanf("%d", &str);
  printf("COLUMNS = ");
  var2 = scanf("%d", &col);
  if ((var1 || var2) != 1) {
    printf("INCORRECT INPUT");
    return 0;
  }
  arr = (int **)calloc(str, sizeof(*arr));
  for (z = 0; z < str; z++)
    arr[z] = (int *)calloc(col, sizeof(*arr[z]));
  if (!arr) {
    printf("Incorrect value\n");
    system("pause");
    return 0;
  }

  do {
    while (i != 0 || j != 0 || x != 0) {
      printf("Индекс строки i = ");
      scanf("%d", &i);
      while ((i > str - 1) || i < 0) {
        printf("INCORRECT INPUT\nИндекс строки i = ");
        scanf("%d", &i);
      }
      printf("Индекс столбца j = ");
      scanf("%d", &j);
      while ((j > col - 1) || j < 0) {
        printf("INCORRECT INPUT\nИндекс столбца j = ");
        scanf("%d", &j);
      }
      printf("Значение элемента x = ");
      scanf("%d", &x);
      arr[i][j] = x;
    }
    print_menu();
    var = scanf("%d", &choice);
    if (var != 1) {
      printf("INCORRECT INPUT");
      break;
    }
    switch (choice) {
    case 1: {
      break;
    }
    case 2: {
      int k, u;
      for (k = 0; k < str; k++) {
        for (u = 0; u < col; u++) {
          if (arr[k][u] == 0)
            printf(" * ");
          else
            printf(" %d ", arr[k][u]);
        }
        printf("\n");
      }
      break;
    }
    case 3: {
      i = 1;
      j = 1;
      x = 1;
      while (i != 0 || j != 0 || x != 0) {
        printf("Индекс строки i = ");
        scanf("%d", &i);
        while ((i > str - 1) || i < 0) {
          printf("INCORRECT INPUT\nИндекс строки i = ");
          scanf("%d", &i);
        }
        printf("Индекс столбца j = ");
        scanf("%d", &j);

        while ((j > col - 1) || j < 0) {
          printf("INCORRECT INPUT\nИндекс столбца j = ");
          scanf("%d", &j);
        }
        if (arr[i][j] != 0) {
          print_menu2();
          var5 = scanf("%d", &choice2);
          if (var5 != 1) {
            printf("INCORRECT INPUT");
            break;
          }
          switch (choice2) {
          case 1: {
            printf("Значение элемента x = ");
            scanf("%d", &x);
            arr[i][j] = x;
            break;
          }
          case 2:
            break;
          }
        } else {
          printf("Значение элемента x = ");
          scanf("%d", &x);
          arr[i][j] = x;
        }
      }
      break;
    }

    case 0: {
      printf("Goodbye\n");
      break;
    }
    }
  } while (choice != 0);
  for (i = 0; i < str; i++)
    free(arr);
  return 0;
}
