#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define SIZE 10000
long long int t; //counter
int product[SIZE]; //product that is produced by producer and consumed by consumer
int pos; //positipn in the array
int consSleep, prodSleep; // "bool" variables for restarting producer and consumer
pthread_t thread_producer, thread_consumer;

void* produce(void*u) //producer function
{
	while(1){
		if (prodSleep)
			continue;
		if (pos==SIZE){ //as it reaches the last element, it should start from the beginning
			consSleep = 0;
			prodSleep = 1;
			printf("Done %lld-th production\n", t++);
			continue;
		}
		product[pos] = pos;
		pos++;
	}
	pthread_exit(NULL);
	return NULL;
	
}

void* consume(void*v)
{
	int j = 0;
	while(1){
		while(product==0);//Wait until buffer is not empty
		if(j%1000==0)
			printf("Consumer %d step %d\n",j,product);//Output number of taken product and the size of buffer
		if(product>0){//Take product
			j++;
			product--;
		}
	}
}

int main(void)
{
	pthread_create(&thread_producer,NULL,&produce,NULL);
	pthread_create(&thread_consumer,NULL,&consume,NULL);
	pthread_join(thread_producer,NULL);
	return 0;
}
