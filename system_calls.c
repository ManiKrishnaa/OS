#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
    char buff[20];
    int fp1,fp2,n;
    fp1 = open(argv[1],O_RDONLY);
    fp2 = open(argv[2],O_WRONLY);
    n = read(fp1,buff,sizeof(buff));
    write(fp2,buff,n);
    close(fp1);
    close(fp2);
}