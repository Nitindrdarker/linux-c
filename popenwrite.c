#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
    FILE *rd;
    char buffer[50];
    sprintf(buffer, "name first");//buffer = name fiirst
    rd = popen("wc -c", "w"); // wc -c is the process which counts the number of bytes same as wc -c counts the words and prints it on terminal for more informatipon write wc --help 
    fwrite(buffer, sizeof(char), strlen(buffer), rd);//to wrtie the data into the file
    printf("\nlen - >%ld\n", strlen(buffer));
    pclose(rd);
}