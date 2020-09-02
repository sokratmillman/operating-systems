#include <stdio.h>

void Bubble_sort(int *arr, int size){
int temp;
int i, j;
for (i = 0; i<size-1; i++){
	for (j = 0; j<size-i-1; j++){
		if (arr[j]>arr[j+1]){
			temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1]=temp;
		}
	} 

} 
}

int main(void){
int i;
int arr[8] = {1, 3, 5, 7, 2, 4, 8, 6};
Bubble_sort(arr, 8);
int k; 
for (k=0; k < 8; k++) 
    printf("%d ", arr[k]); 
printf("\n");

}
