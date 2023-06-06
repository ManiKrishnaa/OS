#include<stdio.h>
int main()
{
    int n,i,bt[30],wt[30],tat[30],pri[30],p[30],k,temp;
    float wtavg,tatavg;
    printf(" enter the number of processes  : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        p[i] = i;
        printf(" enter burst time and priority for each process %d : ",i);
        scanf("%d %d",&bt[i],&pri[i]);
    }
    for(i=0; i<n; i++)
    {
        for(k=i+1; k<n; k++)
        {
            if(pri[i] > pri[k])
            {
                temp = p[i]; // process swapping 
                p[i] = p[k];
                p[k] = temp;
 
                temp = bt[i]; // burst time swapping
                bt[i] = bt[k];
                bt[k] = temp;

                temp = pri[i]; // priority swapping
                pri[i] = pri[k];
                pri[k] = temp;
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
    printf(" \t process \t priority \t burst time \t waiting time \t turn around time \t ");
    for(i=0; i<n; i++)
    {
        printf("\n\t\t p%d \t\t %d \t\t %d \t\t %d \t\t %d \t",p[i],pri[i],bt[i],wt[i],tat[i]);
    }
    printf(" \n total average waiting time : %.2f",wtavg/n);
    printf(" \n total average turn around  time : %.2f",tatavg/n);
}