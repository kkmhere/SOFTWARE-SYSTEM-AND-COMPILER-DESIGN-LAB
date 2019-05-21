#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

int nop,k=0;
char prodset[10][10],str[20];

void recursive(char p)
{
    int found=0,temp,i,j;
    for(i=0;i<nop;i++)
    {
        if(prodset[i][0]==p)
        {
            temp=k;
            int j;
            for(j=2;prodset[i][j];j++)
            {
                if(str[k]=='#')k++;
                if(isupper(prodset[i][j]))
                {
                    found=1;
                    recursive(prodset[i][j]);
                }
                else if(prodset[i][j]==str[k])
                {
                    k++;
                    found=1;
                }
                else if(prodset[i][j]=='#')
                {
                    found=1;
                    break;

                }
                else
                {
                    k=temp;
                    break;
                }
                
            }

        }
    }
    if(i>nop && found==0 && k!=strlen(str))
    {
        printf("INVALID STRING");
        exit(0);
    }
}

int main()
{
    int i;
    printf("\nENTER THE NO OF PRODUCTION");
    scanf("%d",&nop);
    printf("\nENTER THE PRODUCTION IN THE FORM E=E+T");
    for(i=0;i<nop;i++)
    {
        scanf("%s",prodset[i]);
    }
    while(1)
    {
        k=0;
        printf("\n ENTER THE STRING");
        scanf("%s",&str);
        recursive(prodset[0][0]);
        if(k==strlen(str))
        {
            printf("\n VALID");
        }
        else
        {
            printf("\n INVALID");
        }
        
    }
    return 0;

}