#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void){
int fin = open("ex1.txt", O_RDONLY);
int fout = open("ex1.memcpy.txt", O_RDWR);

struct stat forsize = {};
if (fstat(fin, &forsize))
	printf("error\n");
off_t size = forsize.st_size;
ftruncate(fout, size);


char* filein;
char* fileout;
filein = mmap (NULL, size, PROT_READ, MAP_SHARED, fin, 0);
fileout = mmap (NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fout, 0);

memcpy(fileout, filein, size);

}
