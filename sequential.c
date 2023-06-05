#include<stdio.h>
#include<stdlib.h>
int main()
{
    int st,len,f[50],i,j,c; // total blocks = 50
    for(i=0; i<=50; i++)
    {
        f[i] = 0;
    }
    X:
    printf(" enter the starting block and lenght of the file : "); // starting block of the file and length of the file
    scanf("%d %d",&st,&len);
    for(j=st; j<=(st+len); j++)
    {
        if(f[j] == 0) // here f[j] = 0 means nothing is allocted , f[j] = 1 means block is allocated
        {
            f[j] = 1;
            printf("\n %d->%d",j,f[j]);
        }else
        {
            printf(" \n block already alocated .. \n");
            break;
        }
        if(j == (st+len))
        {
            printf(" \n file is allocated to disk \n");
        }
    }
    printf(" do you want to enter more number of files (y-1/n-0) : ");
    scanf("%d",&c);
    if(c == 1)
    {
         goto X;
    }else
    {
         exit(0);
    }
}