#include <stdio.h>

int main() {
  int word_length = 0;
  char c;
  int i;

  FILE *f = fopen("text.txt", "r");
  while ((c = fgetc(f)) != EOF) {
    if (c != ' ')
      word_length++;
    else {
      for (i = 0; i < word_length; i++)
        printf("*");
      printf("\n");
      word_length = 0;
    }
  }
  for (i = 0; i < word_length; i++)
    printf("*");
  fclose(f);

  return 0;
}
