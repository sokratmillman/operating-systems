#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <time.h>

extern int errno;

int main(){
	int i;
	struct rusage* memusage = malloc(sizeof(struct rusage));
	for (i=0; i<10; i++){
	memset (calloc(10*1024*1024, 1), 0, 10*1024*1024);
	if (getrusage(RUSAGE_SELF, memusage)) 
		printf("Error %d\n", errno);
	printf ("Memory usage: = %ld\n", (*memusage).ru_maxrss);
	sleep(1);
	}
	return 0;
}

/*
Memory usage: = 11300
Memory usage: = 21572
Memory usage: = 31868
Memory usage: = 42164
Memory usage: = 52460
Memory usage: = 62756
Memory usage: = 72788
Memory usage: = 83084
Memory usage: = 93380
Memory usage: = 103676
*/
