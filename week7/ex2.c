#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *array;
  int N, i;
  printf("Integer N:\n");
  scanf("%d", &N);
  array = malloc(N*sizeof(int));
  for (i=0; i<N; i++){
    array[i] = i;
  }
  for(i=0; i<N; i++){
    printf("%d ", array[i]);
  }
  free(array);
  return 0;
}
