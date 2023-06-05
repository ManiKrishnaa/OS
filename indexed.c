#include<stdio.h>
#include<stdlib.h>
int main()
{
    int f[50],index[50],i,j,k,n,ib,c;
    for(i=0; i<=50; i++)
    {
        f[i] = 0;
    }
    X:
    printf(" enter the index block :");
    scanf("%d",&ib);
    if(f[ib] == 0)
    {
        f[ib] = 1;
        printf(" \n enter no of files on index : ");
        scanf("%d",&n);
    }else
    {
        printf("\n block already allocated \n");
        goto X;
    }
    printf(" enter : \n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&index[i]);
    }
    for(i=0; i<n; i++)
    {
        if(f[index[i]] == 1)
        {
            printf(" \n block is already allocated .. \n");
            goto X;
        }
    }
    for(j=0; j<n; j++)
    {
        f[index[j]] = 1;
    }
    printf("\n  blocks - allocated ");
    printf(" \n file indexed : \n");
    for(k=0; k<n; k++)
    {
        printf(" %d -> %d : %d \n",ib,index[k],f[index[k]]);
    }
    printf(" \n press 1 to enter more number of files or 0 to exit : ");
    scanf("%d",&c);
    if(c == 1)
    {
        goto X;
    }else
    {
        exit(0);
    }
}