#include<stdio.h>
int main()
{
    int bt[20],tat[20],wt[20],p[20],n,i,k,temp;
    float wtavg,tatavg;
    printf(" enter number of process : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        p[i] = i;
        printf("\n enter burst time for process %d : ",i);
        scanf("%d",&bt[i]);
    }
    for(i=0; i<n; i++)
    {
        for(k=i+1; k<n; k++)
        {
            if(bt[i] > bt[k])
            {
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
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
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    printf(" average waiting time : %.2f\n ",wtavg/n);
    printf(" average turn around time : %.2f ",tatavg/n);
} 