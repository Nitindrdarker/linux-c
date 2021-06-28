
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

printf("in child");
printf("%d",getpid());
}
else
{
    sleep(5);
printf("in parent");
printf("%d",getpid());

}

}

