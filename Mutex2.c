#include<stdio.h>
#include<pthread.h>
int num = 0;
pthread_mutex_t lock;
void thread1()
{
 while(1)
 {
 pthread_mutex_lock(&lock);
 int i = 0;
  for(i= 0; i<=5; i++) {
  	printf("Thread 1- %d\n",num); 
	  num++;
  }
sleep(1);
 pthread_mutex_unlock(&lock);
 sleep(1);
 }
}
void thread2()
{
 while(1)
 {
 pthread_mutex_lock(&lock);
 int j = 5;
 for(j=0; j<=5; j++) {
  	printf("Thread 2- %d\n",num);
  	num++;
  }

 pthread_mutex_unlock(&lock);
 sleep(2);
 }
}
void main()
{
 pthread_t t1,t2;
 pthread_mutex_init(&lock, NULL);
 pthread_create(&t1,NULL,thread1,NULL);
 pthread_create(&t2,NULL,thread2,NULL);
 pthread_join(t1,NULL);
 pthread_join(t2,NULL);
}

