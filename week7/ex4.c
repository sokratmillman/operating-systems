#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void* own_realloc(void* ptr, size_t size){
  void* res;
  if (ptr==NULL)
    return malloc(size);

  if (size==0){
    free(ptr);
    return NULL;
  }

  size_t initsize = sizeof(ptr);

  res = malloc(size);
  memcpy(res, ptr, size);
  free(ptr);
  return res;
}

int main(void) {
  int* arr = malloc(10*sizeof(int));
  for (int i = 0; i<10; i++){
    printf("%d ", arr[i]);
  }
  for (int i = 0; i<10; i++){
    arr[i] = i;
  }
  for (int i = 0; i<10; i++){
    printf("%d ", arr[i]);
  }
  arr = own_realloc(arr, 20*sizeof(int));
  for (int i = 0; i<20; i++){
    printf("%d ", arr[i]); //different numbers because they are not initialized
  }
  return 0;
}
