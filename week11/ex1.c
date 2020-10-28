#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void){
int fileopen = open("ex1.txt", O_RDWR);
struct stat forsize = {};
if (fstat(fileopen, &forsize))
	printf("error\n");
off_t size = forsize.st_size;
char* memor;
char* string = "This is a nice day";
int size1 = strlen(string);
ftruncate(fileopen, size1);
memor = mmap (NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fileopen, 0);
for(int i = 0; i<size1; i++){
	memor[i] = string[i];
}

return 0;
}
