#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<sys/stat.h>
int main()
{
    pid_t p, p1, p2;
    p = fork();
    if(p == 0)
    {
        printf("Im child of %d and my id is %d\n", getppid(), getpid());
        p1 = fork();
        if(p1 == 0)
        {
            printf("Im child of %d and my id is %d\n", getppid(), getpid());
            p2 = fork();
            if(p2 == 0)
            {
                printf("Im child of %d and my id is %d\n", getppid(), getpid());
            }
            else{
                
                printf("Im parent p2 with id %d and my parent id is %d\n", getpid(), getppid());
            wait(NULL);}
        }
        else{
            
            printf("Im parent p1  with id %d and my parent id is %d\n", getpid(), getppid());
            wait(NULL);}
    }
    else{
        printf("Im parent p with id of %d\n", getpid());
        wait(NULL);
        }
}