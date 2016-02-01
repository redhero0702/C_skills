#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* define a global accessible variables and a mutex */
pthread_mutex_t mutexsum;
pthread_t thread1;
pthread_t thread2;
int sum = 0;

struct cbinfo{
	int number;
	char* msg;
};

void* callback(void *args){
	printf("thread ID: %lu\n", pthread_self());
	pthread_mutex_lock(&mutexsum);
	sum += 1;
	pthread_mutex_unlock(&mutexsum);
	return NULL;
}

int main(int argc, char* argv[]){
	struct cbinfo s = {1,"hello"};
	printf("sizeof(pthread_t) -> %lu\n", sizeof(pthread_t));
	pthread_attr_t attr;
	pthread_mutex_init(&mutexsum, NULL);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	int rc1 = pthread_create(&thread1, &attr, callback, (void *) &s);
	if (rc1){
		printf("pthread_create error code: %d\n", rc1);
	}

	int rc2 = pthread_create(&thread2, &attr, callback, (void *) &s);
	if (rc2){
		printf("pthread_create error code: %d\n", rc2);
	}
	pthread_mutex_destroy(&mutexsum);
	pthread_exit(0);
	return 0;
}
