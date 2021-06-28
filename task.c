#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<sys/stat.h>
int main(){
    pid_t p, k;
    p = fork();
    if(p==0)
    {
        printf("i am child having parent id %d ", getppid());
        printf("and my id is %d\n", getpid());
    }
    else
    {
        k = fork();
        if(k==0)
            {
                printf("i am child having parent id %d ", getppid());  
                printf("and my id is %d\n", getpid());
            }
        else{
        printf("i im parent having id as%d\n", getpid());
        }
    }
}
