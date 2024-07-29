#include <stdio.h>

int calcfactorial(int num);

int main()
{
    int num;
    printf("Enter a number to calculate it's factorial: ");
    scanf("%d", &num);
    printf("The factorial of number %d is: %d", num, calcfactorial(num));
    return 0;
}

int calcfactorial(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }
    return fact;
}