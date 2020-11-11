#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	
	int i, numoffiles;
	int appends = 0;
	char sym;
	char *mode;
	if (argc == 1)
	{
		while(fread(&sym, 1, 1, stdin)){
			printf("%c", sym);
		}
	}
	if (argc > 1){
		if(strcmp(argv[0], "-a")){
			mode = "w+";
			numoffiles = argc - 2;
			FILE **files = malloc(numoffiles * sizeof(FILE*));
			for (i = 0; i<numoffiles; i++){
				files[i] = fopen(argv[i+2], mode);
			}
			while (fread(&sym, 1, 1, stdin)){
				for (i = 0; i<numoffiles; i++){
					fwrite(&sym, 1, 1, files[i]);
					fclose(files[i]);
				}
				printf("%c", sym);
				
			}
		}	
		else{
			mode = "w+";
			numoffiles = argc - 1;
			FILE **files = malloc(numoffiles * sizeof(FILE*));
			for (i = 0; i<numoffiles; i++){
				files[i] = fopen(argv[i+1], mode);
			}
			while (fread(&sym, 1, 1, stdin)){
				for (i = 0; i<numoffiles; i++){
					fwrite(&sym, 1, 1, files[i]);
				}
				printf("%c", sym);
			}
		}
		
	}
	return 0;
}
