#include <stdio.h>

int main()
{
    int n, i, sum = 0;

    printf("Enter the size of the array: "); // Prompt user for array size
    scanf("%d", &n);

    int arr[n];

    // Ask the user to input the elements of the array
    for (i = 0; i < n; i++)
    {
        printf("Enter the element number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) // Calculate the sum
    {
        sum += arr[i];
    }

    // Print the sum
    printf("The sum of the array elements is: %d\n", sum);

    return 0;
}
