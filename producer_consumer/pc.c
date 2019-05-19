#include<stdio.h>
#include <stdlib.h>
int mutex=1,empty=3,full=0,x=0;

int signal(int s);
int wait(int s);
void producer();
void consumer();

int main()
{
    int n;
    printf("\n 1.PRODUCER \n 2.CONSUMER \n 3.EXIT");
    while(1)
    {
        printf("\n ENTER YOUR CHOICE");
        scanf("%d",&n);
        switch(n)
        {
            case 1:if(mutex==1 && empty!=0)
                    {
                        producer();
                    }
                    else
                    {
                        printf("BUFFER IS FULL!!");
                    }
                    break;

            case 2:if(mutex==1 && full!=0)
                    {
                        consumer();
                    }        
                    else
                    {
                        printf("\n BUFFER IS EMPTY!!!");
                    }
                    break;

            case 3:exit(0);        
                    
                    
                    
        }
    }
    return 0;
}

int wait(int s)
{
    return --s;
}

int signal(int s)
{
    return ++s;
}

void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\n PRODUCED %d",x);
    mutex=signal(mutex);
}

void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\n CONSUMED %d",x);
    x--;
    mutex=signal(mutex);
}