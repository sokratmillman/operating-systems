#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf("Size of int = %d, value is %d \nSize of float = %d, value is %f\nSize of double = %d, value is %f \n", sizeof(a), a, sizeof(b), b, sizeof(c), c);
}
