#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *mythread(void *vargp)
{
    sleep(1);
    printf("in thread");
    return NULL;
}
int main()
{
    pthread_t thread_id;
    printf("before thread");
    pthread_create(&thread_id, NULL, mythread, NULL);
    pthread_join(thread_id, NULL);
    printf("after thread");
    exit(0);
}