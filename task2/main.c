#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
 FILE *input;
  input = fopen("text.txt", "r");
  if (input == NULL) {
    printf("Unable to open file");
    return 1;
  }
  char c, str[80];
  int word_len = 0;
   while ((c = fgetc(input)) != EOF) {
    if (c == '\t' || c == '\n' || c == ' ') {
      str[word_len] = '\0';
  return 0;
  }
