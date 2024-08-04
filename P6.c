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
    int fact = 1;                   //intial value for factorial variable
    for (int i = 1; i <= num; i++) // a for loop to iterate from 1 until we reach the required number
    {   
        fact *= i;                 // fact = fact * i 
    }
    return fact;
}