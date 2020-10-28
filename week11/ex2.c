#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void){
char* buf;
char* string = "Hello";
int length = strlen(string);
setvbuf(stdout, buf, _IOLBF, length);
for (int i =0; i<length; i++){
	printf("%c", string[i]);
	sleep(1);
}
printf("\n");
return 0;
}
