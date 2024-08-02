#include <stdio.h>

void Bubblesort(int arr[], int n);
void printArr(int arr[], int n);

int main() {
    int arr[] = {-10,10,3,-2,5,-3,7,-8,1,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Before sorting: ");
    printArr(arr, n);
    Bubblesort(arr, n);
    printf("After sorting: ");
    printArr(arr, n);
    
    
    int Max1 = arr[n-1]*arr[n-2]*arr[n-3];
    int Max2 = arr[0]*arr[1]*arr[n-1];

    if(Max1 > Max2){
        printf("Elements[%d,%d,%d]",arr[n-1],arr[n-2],arr[n-3]);
        printf("\n");
        printf("product:%d",Max1);
    }else{
        printf("Elements[%d,%d,%d]",arr[0],arr[1],arr[n-1]);
        printf("\n");
        printf("product:%d",Max2);
    }

    return 0;
}
void Bubblesort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArr(int arr[], int n) {
    printf("array elements[");
    for(int i = 0; i < n; i++) {
        if (i != 0) printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}
