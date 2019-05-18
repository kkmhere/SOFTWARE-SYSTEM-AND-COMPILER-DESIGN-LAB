#include <stdio.h>
#include <stdlib.h>
#define m 10

struct process
{
    int proc;
    int arrival;
    int turn;
    int burst;
    int wait;
};

void sort_arrival(struct process p[],int n);
void swap(struct process *p1,struct process *p2);

int main()
{
    struct process p[m];
    p[0].turn=0;
    p[0].arrival=0;
    p[0].burst=0;
    int i,j,num;
    float total_turn=0,total_wait=0;
    printf("\n ENTER THE NUMBER OF PROCESS");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        p[i].proc=i;
        printf("\n PROCESS %d",i);
        printf("\n ARRIVAL TIME");
        scanf("%d",&p[i].arrival);
        printf("\n BURST TIME");
        scanf("%d",&p[i].burst);
    }

    sort_arrival(p,num);

    for(i=0;i<num;i++)
    {
        if(p[i].arrival<p[i-1].arrival)
        {
            p[i].turn=p[i-1].turn+p[i-1].arrival+p[i].burst-p[i].arrival;
            p[i].wait=p[i-1].turn-p[i].arrival+p[i-1].arrival;
        }
        else
        {
            p[i].turn=p[i].burst;
            p[i].wait=0;
        }
        
    }

    for(i=0;i<num;i++)
    {
        total_turn+=p[i].turn;
        total_wait+=p[i].wait;
    }

    for(i=0;i<num;i++)
    {
        printf("\n WAITING TIME OF proc %d=%d",i,p[p[i].proc].wait);
    }
    printf("\n AVERAGE WAITING TIME %lf ms",total_wait/num);

    for(i=0;i<num;i++)
    {
        printf("\n TURN AROUND TIME OF PROCESS %d=%d",i,p[p[i].proc].turn);
    }
    printf("\n AVERAGE TURN AROUNF TIME %lf ms",total_turn/num);
    return 0;
}

void sort_arrival(struct process p[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(p[j].arrival>p[j+1].arrival)
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
