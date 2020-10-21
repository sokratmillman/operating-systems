#include <stdio.h>
#include <dirent.h>
int main(void) {
  int i=0;
  int j,k;
  DIR *directory = opendir("./tmp");
  struct dirent* readd;
  struct dirent* inodes[10];
  while ((readd=readdir(directory))!=NULL){
    inodes[i]=readd;
    i++;
  }
  for (j = 0; j<i; j++){
    int count = 0;
    int ind[10];
    for (k=j; k<i; k++){
      if(inodes[k]->d_ino == inodes[j]->d_ino){
        ind[count] = k;
        count++;
      }
    }

    if (count>=2){
      printf("Inodenumber: %lu\n", inodes[j]->d_ino);
      for (k=0; k<count; k++){
        printf("%s\n", inodes[ind[k]]->d_name);
      }
    }
  }
}
