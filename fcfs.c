#include<stdio.h>
int main()
{
    int bt[20],tat[20],wt[20],n,i;
    float wtavg,tatavg;
    printf(" enter number of process : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\n enter burst time for process %d : ",i);
        scanf("%d",&bt[i]);
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for(i=1; i<n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    printf("\n process \t burst time \t waiting time \t turn around time \n ");
    for(i=0; i<n; i++)
    {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
    }
    printf(" average waiting time : %.2f\n ",wtavg/n);
    printf(" average turn around time : %.2f ",tatavg/n);
} 