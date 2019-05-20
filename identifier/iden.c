#include <stdio.h>
#include <stdlib.h>
#define m 20

int main()
{
    int i;
    char str[20];
    printf("\n ENTER THE IDENTIFIER");
    gets(str);
    if(!isalpha(str[0]) && str[0]!='_')
    {    printf("\n INVALID!!!");
         return;
    }     

    for(i=0;str[i]!='\0';i++)
    {
        if(!isalnum(str[i]) && str[i]!='_')
        {
            printf("\n INVALID!!!");
            return;
        }
    }
    printf("\n VALID");
    return 0;    
}