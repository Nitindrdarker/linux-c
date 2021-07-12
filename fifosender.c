#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int res, n;
    res = open("fifo", O_WRONLY);//for non blocked write 'O_NONBLOCKED,'
    write(res, "message", 7);
    printf("sender process havving pid %d and send the data\n", getpid());
}