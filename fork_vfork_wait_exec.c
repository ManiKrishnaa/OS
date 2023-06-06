// fork system call

#include<stdio.h>
#include<unistd.h>
int main()
{
    int pid;
    pid = fork();
    if(pid >= 0)
    {
        if(pid == 0)
        {
            printf("\n child process id : %d \n",pid);
        }else
        {
            printf("\n parent process id : %d \n",pid);
        }
    }else
    {
        printf(" \n process is not created \n ");
    }
}

//output

parent process id  : 243

child process id : 0


//vfork - system call

#include<stdio.h>
#include<unistd.h>
int  global = 5;
int main()
{
    int pid,local=6;
    pid = vfork();
    if(pid == 0)
    {
        global++;
        local--;
        exit(0);
    }
    printf("\n global value : %d \t local value : %d",global,local);
    exit(0);
}

//output

global value : 6 local value : 5

//wait - system call

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    int pid,childpid,status;
    printf(" \n parent process with PID %d \n",getpid());
    pid = fork();
    if(pid != 0)
    {
        sleep(1);
        printf("parent process with PID %d PPID  %d \n",getpid(),getppid());
        childpid = wait(&status);
        printf("child process with PID %d is terminated with exit code %d \n",childpid,status>>8);
    }else
    {
        printf(" child process with PID %d PPID %d ",getpid(),getppid());
        sleep(5);
        exit(42);
    }
    printf("  PID %d terminates \n",getpid());
}

//output

parent process with PID is 7242
child process with PID 7243 and PPId 7242
parent process with PID 7242 and PPID 6984
child process PID 7243 terminated with exit code 42
PID 7242 terminates

//exec - system call

#include<stdio.h>
#include<unistd.h>
int main( int argc,char *argv[])
{
   if(fork()==0)
   {
        execvp(argv[1],&argv[1]);
        fprintf(stderr,"couldnot execute %s \n",argv[1]);
   }
}

//output

[dmgv@LinuxServer ~]$ cc filename.c
[dmgv@LinuxServer ~]$ ./a.out samplefilename.txt
Hello welcome to OS lab we are executing execvp() system call



