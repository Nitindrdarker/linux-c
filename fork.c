#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<sys/stat.h>
int main(){
pid_t p;
printf("before fork\n");
p = fork();
if(p==0)
{
printf("i am child having id %d\n", getpid());
printf("my parent id is %d\n", getppid());
}
else
{
wait(NULL);//now child will be executed first
printf("my child id is %d\n", p);
printf("i am parent having id %d\n", getpid());
}
printf("Common\n");
}
