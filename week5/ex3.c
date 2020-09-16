#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define SIZE 20
long long int t; //counter
int product[SIZE]; //product that is produced by producer and consumed by consumer
int pos; //positipn in the array
int consSleep, prodSleep; // "bool" variables for restarting producer and consumer


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
	while(1){
		if (consSleep)
			continue;
		if (pos==0){
			consSleep = 1;
			prodSleep = 0;
			continue;
		}
		printf("%d ", product[pos]);
		pos--;
	}
	pthread_exit(NULL);
	return NULL;
}

int main(void)
{	
	pthread_t thread_producer, thread_consumer;
	consSleep=1;
	pthread_create(&thread_producer,NULL,&produce,NULL);
	pthread_create(&thread_consumer,NULL,&consume,NULL);
	while(1);
	//stopped after 2414688 time was done 
	return 0;
}
//each output starting from the 'bignumber'-th iteration may be incorrect, because producer and consumer try to use the same input (array) without blocking it -> they can change it. in some time it will lead to incorrect output, when consumer stores the old value while producer already changed it; this is so-called race condition.
