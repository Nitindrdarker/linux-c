#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
void *fun1();
void *fun2();
int shared = 1;
sem_t s;// semaphore variable
int main()
{
    sem_init(&s, 0, 1);//initilize semaphores variable 1st argument if address of variabe 2nd argument if number of proecess (for threads its valu is 0) 3rd argumnet if value of semaphores
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("funal value of shared variable %d\n",shared);
}
void *fun1()
{
    int x; 
    sem_wait(&s);//executes wait operations on s
    x = shared;
    printf("Thread1 reads the value as %d\n",x);
    x++;
    printf("local updation by thread1 %d\n", x);
    sleep(1);
    shared = x;
    printf("value of shared variable updated by thread1 if %d\n", shared);
    sem_post(&s);

}
void *fun2()
{
    int y; 
    sem_wait(&s);//executes wait operations on s
    y = shared;
    printf("Thread2 reads the value as %d\n",y);
    y--;
    printf("local updation by thread2 %d\n", y);
    sleep(1);
    shared = y;
    printf("value of shared variable updated by thread2 if %d\n", shared);
    sem_post(&s);

}