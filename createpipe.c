#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
    int res;
    res = mkfifo("fifo",0777);//create a named pipe with the name fifo
    printf("named pipe create");
}