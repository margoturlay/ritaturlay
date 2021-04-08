#include <stdio.h>
 
int main()
{
    int word_length = 0;
    char c;
    int i;
 
    while((c = getchar()) != '\n')                 
    {
        if (c != ' ')                              
            word_length++;         
        else                                      
        {
            for(i = 0; i < word_length; i++)   
                printf("*"); 
            printf("\n");        
            word_length = 0; 
        }
    }
 
    for(i = 0; i < word_length; i++) 
        printf("*");            
                    
 
    return 0;
}
