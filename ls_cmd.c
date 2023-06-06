#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    int pid;
    pid = fork();
    if(pid < 0)
    {
        printf(" \n fork failed \n");
        exit(-1);
    }else if(pid == 0)
    {
        execlp("/bin/ls","ls","-1",NULL);
    }else
    {
        wait(NULL);
        printf("\n child complete \n");
        exit(0);
    }
}