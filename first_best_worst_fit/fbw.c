#include <stdio.h>
#include <stdlib.h>

int procmem[100],tempmem[100],mem[100];
int noproc,nomem;

void first_fit(int mem[])
{
    int i,j;
    printf("\nFIRST\nProcess\t\tMemory");
    for(i=0;i<noproc;i++)
    {
        int flag=0;
        for(j=0;j<nomem;j++)
        {
            if(procmem[j]<mem[j])
            {
                flag=1;
                mem[j]-=procmem[j];
                printf("%d\t\t%d",i+1,j+1);
                break;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
    if(i!=noproc)
    {
        printf("\n CANT ALLOCATE ANYMORE");
    }
}

void worst_fit(int mem[100])
{
    int i,j;
    printf("\n WORST \n PROCESS \t\t MEMORY");
    for(i=0;i<noproc;i++)
    {
        int high=-1;
        for(j=0;j<nomem;j++)
        {
            if(procmem[j]<=mem[j])
            {
                if(mem[high]<mem[j] || high==-1)
                    high=-1;
            }
        }
        if(high!=-1)
        {
            mem[high]-=procmem[high];
            printf("\n %d\t\t%d",i+1,j+1);
        }
        else
        {
            printf("\n CANT ALLOCATE ANYMORE");
            return;
        }
        
    }
    
}

void best_fit(int mem[100])
{
    int i,j;
    printf("\n BEST \n PROCESS \t\t MEMORY");
    for(i=0;i<noproc;i++)
    {
        int low=-1;
        for(j=0;j<nomem;j++)
        {
            if(procmem[j]<=mem[j])
            {
                if(mem[low]>mem[j] || low==-1)
                    low=-1;
            }
        }
        if(low!=-1)
        {
            mem[low]-=procmem[low];
            printf("\n %d\t\t%d",i+1,j+1);
            
        }
        else
        {
            printf("\n CANT ALLOCATE!!!");
            return;
        }
        
    }
}

void restore()
{
    int i;
    for(i=0;i<noproc;i++)
    {
        mem[i]=tempmem[i];
    }
}

int main()
{
    int i,ch;
    printf("\n ENTER THE NO OF PROCESS AND NO OF MEMORY BLOCK REQUIRED");
    scanf("%d%d",&noproc,&nomem);
    printf("\n ENTER THE SIZE OF MEMORY BLOCK");
    for(i=0;i<nomem;i++)
    {
        scanf("%d",&tempmem[i]);
    }

    printf("\n ENTER SIZE OR MEMORY REQUESTED");
    for(i=0;i<noproc;i++)
    {
        scanf("%d",&procmem[i]);
    }

    while(1)
    {
        printf("\n 1.FIRST \n 2.WORST \n 3.BEST");
        scanf("%d",&ch);
        restore();
        if(ch==1)
            first_fit(mem);
        else if(ch==2)
            worst_fit(mem);
        else if(ch==3)
            best_fit(mem);
        else
        {
            exit(0);
        }
                    
    }

}