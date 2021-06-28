#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<sys/stat.h>
int main(){
    pid_t p, c;
    p = fork();
    if(p == 0)
    {
        c = fork();
        if(c == 0)
        {
            printf("im child 2 with id %d and my parent is %d\n", getpid(), getppid());
        }
        else{
            wait(NULL);
            printf("im child 1 with id %d and my parent is %d\n", getpid(), getppid());
        }
    }
    else{
        wait(NULL);
        printf("im parent with id %d\n", getpid());
    }
}