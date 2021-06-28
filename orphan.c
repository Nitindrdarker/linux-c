#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
pid_t p;
printf("before fork\n");
p = fork();
if(p==0)
{
sleep(5);//child sleeps for 5 sec and parent will exit after its executation 
printf("i am child having id %d\n", getpid());
printf("my parent id is %d\n", getppid());
}
else
{

printf("my child id is %d\n", p);
printf("i am parent having id %d\n", getpid());
}
printf("Common\n");
}

