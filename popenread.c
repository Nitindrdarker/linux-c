#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
    FILE *rd;
    char buffer[50];
   
    rd = popen("ls", "r");//pipe opened in reading mode
    fread(buffer, 1, 20, rd);//to read only 20 charcters
    write(1, buffer, 20);
    printf("\n");
    pclose(rd);
}