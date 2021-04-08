#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

char* lower(char* str)
{
  int i = 0;
  char ch;
  puts("\nВведите строку символов: ");
  while ((ch = getchar()) != '\n') { 
    if (ch == ' ') continue;
        if(ch >= 'A' && ch <= 'Z') 
            ch = ch + 32;
  str[i++] = ch;
  }
  str[i] = '\0'; 
  return str;
}

int Stringlen(char* name) {
    int size = 0, i;
    for(i = 0; name[i] != '\0'; i++ )
        size++;
    return size;
}

char *mystrcpy(char *d, char *s){
   char *saved = d;
   while ((*d++ = *s++) != '\0');
       return saved;
}

int main() {
char str[80], str2[80];
char* a, res[100] = "", *pa=NULL, *pb=NULL;
char* b;

a = lower(str);
b = lower(str2);


for(pb=str+Stringlen(a); pb!=str; --pb){
  *pb='\0';
    for(pa=a; *pa; ++pa){
        if(mystrstr(str2, pa)&&(Stringlen(pa)>Stringlen(res))){
            mystrcpy(res, pa);
        }
    }
}
puts(*res?res:"not found");
return 0;
}


char* poisk_podstroki(char *a, char *b)
{

    int schet = 0;
    char* check = "", itog = "";
    while (schet!=Stringlen(a))
    {
        for (int i = 0; i < Stringlen(a); i++)
        {
            if (i + schet >= Stringlen(b))
                break;
            if (Stringlen(check) > Stringlen(itog))
                itog = check;
            if (a[i] == b[i + schet])
            {
                check += a[i];
            }
            else
            {
                check = "";
            }
        }
        schet++;
        check = "";
    }
    printf("%c", itog); 
    return itog;
}
 
int main()
{
    char str[80], str2[80];
    char str[80], str2[80];
    char* a, res[100] = "", *pa=NULL, *pb=NULL;
    char* b;

    a = lower(str);
    b = lower(str2);
 
    poisk_podstroki(a, b);
}