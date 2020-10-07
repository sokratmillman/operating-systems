#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	int i;
	for (i = 0; i<10; i++){
		char* mem = (char*)malloc(10*1024*1024);
		memset(mem, 0, 10*1024*1024);
		sleep(1);
	}
	return 0;
}


/*
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 2  0 224176 200908 111988 2397528    0    3    40    51  368   94 10  2 87  1  0
 0  0 224176 195460 111996 2393780    0    0   220    88 1520 3545  4  3 92  1  0
 1  0 224176 190924 111996 2393936    0    0     0     0 1834 4837 10  4 87  0  0
 0  0 224176 185380 111996 2393860    0    0    88     0 2049 5635 12  3 84  1  0
 1  0 224176 175804 111996 2393036    0    0     0    52 1823 4819  9  5 86  0  0
 0  0 224176 164432 112004 2394712    0    0     0   424 2125 6044 11  4 84  1  0
 1  0 224176 134240 112004 2413512    0    0     0     0 1732 4654  7  4 90  0  0
 3  0 224176 138572 112004 2398880    0    0     0     0 1486 3858  3  1 95  0  0
 0  0 224176 128256 112004 2398920    0    0     0     0 1311 2628  3  1 96  0  0
 0  0 224176 119128 112004 2398920    0    0     0     0 1235 2581  4  3 93  0  0

Swap isn't loaded, computer manages jobs itself, that's why si and so don't really change their values



For ex3 there is a .txt doc with result

*/
