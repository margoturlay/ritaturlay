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

int compare( char str2[5]) {
  lower(str2);
  if (strcmp(str2, "fghh")) {
    printf("Invalid password.\n");
  return 1;
  }
  return 0;
}


int main() {
char str[80], str2[80];
char* a, res[100] = "", *pa=NULL, *pb=NULL;
char* b;
a = lower(str);
b = lower(str2);


for(pb=str+strlen(a); pb!=str; --pb){
*pb='\0';
for(pa=a; *pa; ++pa){
if(strstr(str2, pa)&&(strlen(pa)>strlen(res))){
strcpy(res, pa);
}
}
}
puts(*res?res:"not found");

   return 0;
}
