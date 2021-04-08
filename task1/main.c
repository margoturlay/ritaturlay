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

int strCmp(char string1[], char string2[] )
{
    int i;
    for (i = 0; ; i++)
    {
        if (string1[i] != string2[i])
        {
            return string1[i] < string2[i] ? -1 : 1;
        }

        if (string1[i] == '\0')
        {
            return 0;
        }
    }
}

int Stringlen(char* name) {
    int size = 0, i;
    for(i = 0; name[i] != '\0'; i++ )
        size++;
    return size;
}


char *strcpynew(char *d, char *s){
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
        if(strstr(str2, pa)&&(Stringlen(pa)>strlen(res))){
            strcpynew(res, pa);
        }
    }
}
puts(*res?res:"not found");
return 0;
}
