#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
/*
Each fork doubles number of processes -> n-th fork creates 2^(n-1) procces (overall there will be 2^n)
Hence, when loop is run 3 times, fork() is executed 3 times -> 8 processes are created
ex2----ex2----ex2----ex2
     |      |
     |      L_ex2
     L-ex2----ex2
     L-ex2
If there were 5 iterations, there would be 32 processes in pstree
 */

int main(){
	int i;
	for(i=0;i<5;++i){
		fork();
	}
	sleep(5);
	return 0;
}
