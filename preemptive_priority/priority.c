#include <stdio.h>
#include <stdlib.h>
#define m 10

struct process
{
    int turn;
    int burst;
    int priority;
    int rem;
    int arrival;
    int wait;
    int proc;
};

void sort_priority(struct process p[],int n);
void sort_proc(struct process p[],int n);
void swap(struct process *p1,struct process *p2);

int main()
{
    struct process p[m];
    double total_turn=0,total_wait=0;
    int i,j,k,n;

    printf("\n ENTER THE NUMBER OF PROCESS");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\n PROCESS %d",i+1);
        printf("\n ARRIVAL TIME: ");
        scanf("%d",&p[i].arrival);
        printf("\n BURST TIME :");
        scanf("%d",&p[i].burst);
        printf("\n PRIORITY : ");
        scanf("%d",&p[i].priority);
        p[i].proc=i+1;
        p[i].wait=0;
        p[i].rem=p[i].burst;
    }

    sort_priority(p,n);

    for(i=0,k=0;k<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((p[j].arrival<i) && (p[j].rem != 0))
            {
                p[j].rem--;
                if(p[j].rem==0)
                {
                    k++;
                    p[j].wait=i+1-(p[j].burst+p[j].arrival);
                    p[j].turn=p[j].wait+p[j].burst;
                }
                break;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        total_wait+=p[i].wait;
        total_turn+=p[i].turn;
    }

    sort_proc(p,n);

    for(i=0;i<n;i++)
    {
        printf("\n WAITING TIME FOR PROC %d=%d",i+1,p[i].wait);
    }

    printf("\n AVERAGE WAITING TIME :%d",total_wait/n);

    for(i=0;i<n;i++)
    {
        printf("\n TAT FOR PROCESS %d=%d",i+1,p[i].turn);
    }

    printf("\n AVERAGE TAT :%d",total_turn/n);
}

void sort_priority(struct process p[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].priority<p[j+1].priority)
                swap(&p[j],&p[i+1]);
        }
    }
}

void sort_proc(struct process p[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].proc<p[j+1].proc)
                swap(&p[j],&p[j+1]);
        }
    }
}

void swap(struct process *p1,struct process *p2)
{
    struct process temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}
