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
    int c;

    while ((c = getchar()) != EOF)
    {

        if(c == ' ' || c == '\t' || c == '\n')
        {
            putchar('\n');
            
            while ((c = getchar()) == ' ' || (c = getchar()) == '\t' || (c = getchar()) == '\n')
            {
                putchar('\r');  
            }
        }
        putchar('-');
     }
  return 0;
  }
