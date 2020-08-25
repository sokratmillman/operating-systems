#include <stdio.h>
#include <limits.h>
#include <float.h>

void swap(int *v1, int *v2){
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

int main(void) {
	int k, l;
	printf("Write two integers:\n");
	scanf("%d %d", &k, &l);
	swap(&k, &l);
	printf("%d %d\n", k, l);
	return 0;
}
