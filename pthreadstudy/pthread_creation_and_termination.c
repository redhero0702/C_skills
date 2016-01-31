#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


struct threadinfo{
	int ID;
	char* threadname;
};

void *thread1_callback(void *t){
	printf("thread1_callback is running...\n");
	return NULL;
};

int main(int argc, char *argv[]){
	
	pthread_t thread1;
	struct threadinfo thread1_info;
	int rc = pthread_create(&thread1, NULL, thread1_callback, (void*) &thread1_info);
	if (rc){
		printf("pthread_create return error code: %d\n", rc);
		exit(-1);
	}

	pthread_exit(NULL);

	return 0;
}
