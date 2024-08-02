#include <stdio.h>
int main()
{
    int z;
    printf("enter the n of numbers ");
    scanf("%ld", &z);
    int numbers[z];
    for (int x = 0; x < z ; x++)
    {
        printf("enter number  %d = ", x + 1);
        scanf("%ld", &numbers[x]);
    }

    int sum = 0;
    for (int i = 0; i < z ; i++)
    {
        sum += numbers[i];
    }
    float avrage = sum /z;
    printf(" the avrage is = %f", avrage);
    return 0;
}