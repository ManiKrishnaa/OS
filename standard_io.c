#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
    FILE *fp1,*fp2;
    int ch;
    fp1 = fopen(argv[1],"r");
    fp2 = fopen(argv[2],"w");
    while((ch = fgetc(fp1)) != -1)
    {
        fputc(ch,fp2);
    }
}