#include <stdio.h>
#include <ctype.h>

void fi(char c,int q1,int q2);

int count,n=0;
char prod[10][10],first[10];

int main()
{
    int i,choice;
    char c,ch;
    printf("\n ENTER THE NO OF PRODUCTIONS");
    scanf("%d",&count);
    printf("\n ENTER THE %d PROD #=\n\n",count);
    for(i=0;i<count;i++)
    {
        scanf("%s%c",prod[i],&ch);
    }
    do
    {
        n=0;
        printf("\n ELEMENT=");
        scanf("%c",&c);
        fi(c,0,0);
        printf("\n FIRST(%c)={",c);
        for(i=0;i<count;i++)
        {
            printf("%c",first[i]);
        }
        printf("}");
        printf("\n PRESS 1 TO CONTINUE");
        scanf("%d%c",&choice,&ch);
    } while (choice==1);
    return 0;
}

void fi(char c,int q1,int q2)
{
    int j;
    if(!isupper(c))
        first[n++]=c;
    for(j=0;j<count;j++)
    {
        if(prod[j][0]==c)
        {
            if(prod[j][2]=='#')
            {
                if(prod[q1][q2]=='\0')
                {
                    printf("NOT FOUND!!");
                    first[n++]=' ';
                }
                else if(prod[q1][q2]!='\0' && (q1!=0 || q2!=0))
                {
                    fi(prod[q1][q2],q1,(q2+1));

                }
                else
                {
                    first[n++]='#';
                }
                
                
            }
            else if(!isupper(prod[j][2]))
            {
                first[n++]=prod[j][2];
            }
            else
            {
                fi(prod[j][2],j,3);
            }
            
        }
    }    
}
