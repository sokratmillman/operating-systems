#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>

int main(){
	char command[32];
	while(true){
		printf("> ");
		scanf("%s", command);
		system(command);
	}
}

/*we create a string of some fixed length (32 in this case) and scan input for string, then by using system() and giving a string as an parameter, we can use some commands that have no arguments(ls, for example)*/
