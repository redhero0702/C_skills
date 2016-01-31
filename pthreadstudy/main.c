#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_THREADS 5

struct thread_data{
	int  thread_id;    
	int  sum;
	char *message;
};

struct thread_data thread_data_array[NUM_THREADS];

void *PrintHello(void *threadarg){
	struct thread_data mydata;
	mydata = *(struct thread_data*) threadarg;
	printf("Thread ID:%d\n", mydata.thread_id);
	printf("Thread sum:%d\n", mydata.sum);
	printf("Thread message:%s\n", mydata.message);
	pthread_exit(NULL);
}

int main (int argc, char* argv[]){
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;

	/*setting message array*/
	char *messages[NUM_THREADS];
	char *greeting[5];
	char *orderid[5];

	/*malloc for message arr*/
	for (t=0; t<NUM_THREADS; t++){
		messages[t] = (char*) malloc(100);
	}

	/*malloc for orderid */
	for (t=0; t<NUM_THREADS; t++){
		orderid[t] = (char*) malloc(50);
	}

	/*malloc for greeting and assigning value */
	for (t=0; t<NUM_THREADS; t++){
		greeting[t] = "Hello message from ";
	}

	/*convert long type into string*/
	for (t=0; t<NUM_THREADS; t++){
		sprintf(orderid[t],"%ld",t);
		printf("orderid[%ld] -> %s\n", t,orderid[t]);
	}

	for (t=0; t<NUM_THREADS; t++){
		printf("greeting[%ld] -> %s, orderid[%ld] -> %s\n", t,greeting[t],t,orderid[t]);
		printf("addr of greeting[%ld] -> %p\n", t, greeting[t]);
		//strcat(greeting[t], orderid[t]);
		//messages[t] = strcat(greeting[t], orderid[t]); 
	}

	for (t=0; t < NUM_THREADS; t++){
		thread_data_array[t].thread_id = t;
		thread_data_array[t].sum = 0;
		thread_data_array[t].message = messages[t];
		printf("creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *) &thread_data_array[t]);
		if (rc){
			printf("ERROR; return code:%d from pthread_create\n", rc);
			exit(-1);
		}
	}

	return 0;
}
