#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
    void *shared_memory;
    int shmid;
    char buff[100];
    shmid = shmget((key_t)2345,1024,0666|IPC_CREAT);
    printf(" key of shared memory : %d \n",shmid);
    shared_memory = shmat(shmid,NULL,0);
    printf(" process at %p \n",shared_memory);
    printf(" enter some data to shared memory : \n");
    read(0,buff,100);
    strcpy(shared_memory,buff);
    printf(" you wrote : %s \n",(char *)shared_memory);
}