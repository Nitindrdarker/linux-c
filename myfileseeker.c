#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
int  n, fd, fd1;
char buff[50];
fd = open("myfile", O_RDONLY);
n=read(fd,buff,10);
fd1 = open("towrite", O_WRONLY|O_CREAT);
write(fd1, buff, n);
}
