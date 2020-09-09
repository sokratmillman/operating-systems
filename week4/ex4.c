#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>

int main()
{
	char command[128];
	int pid = fork();
	
		while(true) {
		    /*printf("pid=%d; n=%d", getpid(), n);*/
		    if (pid == 0){
		    printf(">>");
		    fgets(command, 128, stdin);
		    system(command);}
		}
	return 0;
}
/*creating a line with command, using fork() and system() to execute in background. program executes in a */
