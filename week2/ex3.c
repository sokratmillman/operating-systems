#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char *argv[]) {
  int n;

  sscanf(argv[1], "%d", &n);
  for (int i = 0; i < n; i++){
  	for (int j = 0; j<n-i; j++){
  		printf("%s", " ");
  	}
  	for (int k = 0; k<2*i+1; k++){
  		printf("%s", "*");
  	}
  	printf("\n");
  }
}
