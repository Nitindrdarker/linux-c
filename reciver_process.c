#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)1122, 1024, 0666);//create the shared memory segment with key 2345
    printf("Key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);//proess attached to shared memory segment
    printf("Process attached at %p\n", shared_memory);//this print the address where the segment is attached
    printf("You wrote : %s\n", (char *)shared_memory);
}