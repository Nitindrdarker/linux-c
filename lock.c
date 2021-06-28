#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void *func1();
void *func2();
int shared = 1;
pthread_mutex_t l;
int main()
{
    pthread_mutex_init(&l, NULL);//initilizeing mutex lock
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final Value of Shared is %d\n", shared);//print the value 

}
void *func1()
{
    int x;
    printf("Thread1 trying to acquire lock\n");
    pthread_mutex_lock(&l);
    printf("thread1 aquired lock \n");
    x = shared;
    printf("thread1 reads  the value of shared variabel as %d\n", x);
    x++;
    printf("local updation by thread1 :%d\n", x);
    sleep(1);//thread 1 is preampted by thread 2
    shared = x;//thread 2 updates the value of shard variable
    printf("value if shaed variable updated by thread1 is %d\n", shared);
    pthread_mutex_unlock(&l);
    printf("thread1 released the lock \n");
}
void *func2()
{
    int y;
    printf("Thread2 trying to acquire lock\n");
    pthread_mutex_lock(&l);
    printf("thread2 aquired lock \n");
    y = shared;
    printf("thread2 reads  the value of shared variabel as %d\n",y);
    y--;
    printf("local updation by thread2 :%d\n", y);
    sleep(1);//thread 2 is oeaempted by thread 1
    shared = y;//thread 2 if updated the value of shared variable
    printf("value if shaed variable updated by thread2 is %d\n", shared);
    pthread_mutex_unlock(&l);
    printf("thread2 released the lock \n");
}