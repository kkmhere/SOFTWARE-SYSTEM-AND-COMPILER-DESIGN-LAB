#include <stdbool.h>
#include<stdlib.h>
#include <stdio.h>
#define s 100
int nextproc(int work[],int current);
bool safeseq();

int N;
int R;
int allocation[s][s];
int need[s][s];
int max[s][s];
int available[s];
int safesequence[s];
int finish[s];

int main()
{
    int i,j;
    bool exist=false;
    printf("\n ENTER THE NUMBER OF PROCESS");
    scanf("%d",&N);
    printf("\n ENTER THE TYPE OD RESOURCES");
    scanf("%d",&R);
    printf("\n ENTER THE allocation MATRIX");
    for(i=0;i<N;i++)
    {
        for(j=0;j<R;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }

    printf("\n ENTER THE MAX MATRIX");
    for(i=0;i<N;i++)
    {
        for(j=0;j<R;j++)
        {
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }

    printf("\n ENTER THE AVAILABLE ARRAY");
    for(i=0;i<R;i++)
    {
        scanf("%d",&available[i]);
    }

    exist=safeseq();

    if(exist)
    {
        for(i=0;i<N;i++)
        {
            printf("\n SAFE SEQUENCE IS");
            printf("p%d",safesequence[i]);
        }    
    }
    else
    {
        printf("\n SAFE SEQUENCE DOES NOT EXIST");
    }
    return 0;
}

bool safeseq()
{
    int work[s];
    int current=-1;
    int i,j;
    int k=0;
    for(i=0;i<k;i++)
    {
        work[i]=available[i];
        finish[i]=false;
    }

    while(true)
    {
        current=nextproc(work,current);
        if(current!=-1)
        {
            for(j=0;j<R;j++)
            {
                work[j]+=allocation[current][j];
                safesequence[k++]=current;
                continue;
            }
        }
        else
        {
            for(i=0;i<N;i++)
            {
                if(finish[i]=false)
                {
                    return false;
                }
                return true;
            }
        }
        
    }
}

int nextproc(int work[],int current)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        current=(current+1)%N;
        if(finish[current])continue;
        bool flag=true;
        for(j=0;j<R;j++)
        {
            if(need[current][j]>work[j])
            {
                flag=false;
                break;
            }
        }
        if(flag=false)
        {
            continue;
        }
        return current;
    }
    return -1;
}
