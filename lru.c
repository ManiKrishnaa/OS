#include<stdio.h>
int fr[3];
void display()
{
    printf("\n");
    for(int i=0; i<3; i++)
    {
        printf("%d \t",fr[i]);
    }
}
int main()
{
    display();
    int page[10] = {1,2,3,4,1,2,3,1,1,2},i,j,k,l,flag1=0,flag2=0,top=0,frsize=3,pf=0,fs[3],index;
    for(i=0; i<3; i++)
    {
        fr[i] = -1;
    }
    for(j=0; j<10; j++)
    {
        flag1 = 0;
        flag2 = 0;
        for(i=0; i<10; i++)
        {
            if(fr[i] == page[j])
            {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }
        if(flag1 == 0)
        {
            for(i=0; i<frsize; i++)
            {
                if(fr[i] == -1)
                {
                    fr[i] = page[i];
                    flag2 = 1;
                    break;
                }
            }
        }
        if(flag2 == 0)
        {
            for(i=0; i<frsize; i++)
            {
                fs[i] = 0;
            }
            for(l=j-1,l=1; l<=frsize-1; l++,k--)
            {
                for(i=0; i<frsize; i++)
                {
                    if(fr[i] == page[k])
                    {
                        fs[i] = 1;
                    }
                }
            }
            for(i=0; i<3; i++)
            {
                if(fs[i] == 0)
                {
                    index = i;
                }
            }
            fr[index] = page[j];
            pf++;
        }
        display();
    }
    printf("\n number of page faults : %d",pf+frsize);
}