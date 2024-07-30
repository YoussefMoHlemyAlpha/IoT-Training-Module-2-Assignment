#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    // dynamically allocates memory for two arrays L and R.
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));  

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];            
              i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the allocated memory for temporary arrays
    free(L);
    free(R);
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the median of the array
double findMedian(int arr[], int size) {
    if (size % 2 != 0) {
        return (arr[size/2]);
    } else {
         return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
}

int main() {
    int size;

    // 1) Prompt the user to enter the size of the array
    printf(" Please , Enter the size of the array: ");
    scanf("%d", &size);

    // 2) Dynamically allocate memory for the array
    int *arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    // 3) Fill the array with random integer values between 1 and 100
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // 4) Display the original array
    printf("Original array: ");
    displayArray(arr, size);

    // 5) Implement the Merge Sort algorithm to sort the array in ascending order
    mergeSort(arr, 0, size - 1);

    // 6) Display the sorted array
    printf("Sorted array: ");
    displayArray(arr, size);

    // 7) Find the median value of the sorted array and display it
    double median = findMedian(arr, size);
    printf("Median value = : %.2f\n", median);

    // 8) Deallocate the memory for the array
    free(arr);

    return 0;
}
