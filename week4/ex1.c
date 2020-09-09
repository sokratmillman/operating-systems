#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	pid = fork();
	int i=10;
		if (pid>0)
			printf("Hello from parent [%d - %d]\n", pid, i);
		else if (pid==0)
			printf("Hello from child [%d - %d]\n", pid, i);
		else
			return EXIT_FAILURE;
	return EXIT_SUCCESS;
}
/*using .sh script we will later run this program 10 times
it will write something like 
Hello from parent [13505 - 10]
Hello from child [0 - 10]
Hello from parent [13507 - 10]
Hello from child [0 - 10]
Hello from parent [13509 - 10]
Hello from child [0 - 10]
Hello from parent [13511 - 10]
Hello from child [0 - 10]
Hello from parent [13513 - 10]
Hello from child [0 - 10]

as for every running of program 2 processes are created by fork() which copies almost everything, but one of them is child and has a pid equal to 0, and that is checked by "if"-block
 */
