#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int res, n;
    char buffer[50];
    res = open("fifo", O_RDONLY);//for non blocked write 'O_NONBLOCKED,'
    n = read(res, buffer, 100);
    printf("reader process having pid %d started\n", getpid());
    printf("data received by reciver %d is : %s\n", getpid(), buffer);
}