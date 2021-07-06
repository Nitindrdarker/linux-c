#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("before\n");
    execl("/bin/ls","ls","-l", NULL);
    printf("after");
}
/*The exec family of functions replaces
 the current running process with a new process.*/