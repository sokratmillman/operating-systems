#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>
int main(void) {
	char chr[128];
	printf("Write the string:");
	scanf("%s", chr);
	for (int i = strlen(chr)-1; i>=0; i--){
  	  printf("%c", chr[i]);
	}
	printf("\n");
	return 0;
}
