#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int a = 10;
int b = 12;
void *sum()
{
    printf("result = %d\n", a + b);
}
void *diff()
{
    printf("result = %d\n", a - b);
}
int main()
{
    printf("1st number = %d and 2nd number = %d\n", a, b);
    pthread_t th1, th2;
    pthread_create(&th1, NULL, sum, NULL);
    pthread_create(&th2, NULL, diff, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    printf("completed");
    exit(0);
}