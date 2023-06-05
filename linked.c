#include<stdio.h>
#include<stdlib.h>
int main()
{
    int f[50],i,j,b,bn,k,len,st,c;
    for(i=0; i<=50; i++)
    {
        f[i] = 0;
    }
    printf("\n enter the blocks already allocated : ");
    scanf("%d",&b);
    printf("\n enter the block no.s that are already allocated : ");
    for(i=0; i<b; i++)
    {
        scanf("%d",&bn);
        f[bn] = 1;
    }
    X:
    printf(" enter the starting index and length : ");
    scanf("%d %d",&st,&len);
    k = len;
    for(j=0; j<(k+st); j++)
    {   
        if(f[j] == 0)
        {
            f[j] = 1;
            printf(" %d - > %d \n",j,f[j]);
        }else
        {
            printf(" %d -> file is already allocated .. \n",j);
            k++;
        }
    }
    printf(" press 1 for more number of files or 0 to exit : ");
    scanf("%d",&c);
    if(c == 1)
    {
        goto X;
    }else
    {
        exit(0);
    }
}