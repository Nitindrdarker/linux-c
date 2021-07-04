#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<sys/stat.h>
int main()
{
    int fd[2], n;
    char buffer[100];
    pid_t p;
    pipe(fd);//create a unidirectional pipe with two end fd[0] and fd[1]
    p = fork();
    if(p > 0)
    {
        printf("parent passing value to chile\n");
        write(fd[1], "hello\n", 6);
        wait(NULL);
    }
    else//child
    {
        printf("child printing reveived value \n");
        n = read(fd[0], buffer, 100);
        write(1, buffer, n);
    }
}