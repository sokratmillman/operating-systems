#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* output(void*u)
{
	printf("Thread number %d created\nMessage from thread number %d\n", *((int*)u), *((int*)u));
}

int main(void)
{
	pthread_t thr;
	int n, i;
	printf("Enter the number n: \n");
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		pthread_create(&thr, NULL, &output, (void*)&i);
		pthread_join(thr, NULL);
	}
	return 0;
}
/*lines are mixed up if thread isn't pthread_join'ed, because they are runned in parallel, but in this form the problem is solved*/
