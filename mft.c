#include<stdio.h>
int main()
{
    int total_mry,bs,p=0,i,mp[30],nob,tif,ef,n;
    printf(" enter total memory available : ");
    scanf("%d",&total_mry);
    printf(" enter block size of each memory : ");
    scanf("%d",&bs);
    nob = total_mry/bs;
    ef = total_mry - nob*bs;
    printf(" enter number of processes : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf(" enter the memory allocated to each process %d : ",i+1);
        scanf("%d",&mp[i]);
    }
    printf(" no of blocks available in memory : %d\n",nob);
    printf("\n PROCESS \t MEMORY REQ \t ALLOCTED \t INT.FRAGMENTATION  \n");
    for(i=0;i<n && p<nob; i++)
    {
        printf("%d\t\t%d",i+1,mp[i]);
        if(mp[i] > bs)
        {
            printf("\t\t NO \t\t -- \n");
        }else
        {
            printf("\t\t YES \t\t %d \n",bs-mp[i]);
            tif += bs-mp[i];
            p++;
        }
    }
    if(i < n)
    {
        printf("\n memory is full ");
    }
    printf(" total internal fragmentation : %d\n",tif);
    printf(" total external fragemenatation : %d",ef);
}