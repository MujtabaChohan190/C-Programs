#include <stdio.h>
int main()
{
    int i = 2;
    int n;
    int not_prime = 0;
    printf("Enter number to check if its prime number: ");
    scanf("%d", &n);

    if (n == 0 || n == 1)
    {
        not_prime = 1;
    }
    else
    {

        for (i = 2; i < n; i++)
        {
            if (n % i == 0 && n != 2) // n!=2 is done , so that when n is 2 , it doesnt lead that 2 is not a prime number bcs when i will be 2 and n will be 2 , it will compute that
            {
                not_prime = 1;
                break;
            }
        }
    }
    if (not_prime)
    {
        printf("%d is not prime number.\n", n);
    }
    else
    {
        printf("%d is prime number.\n", n);
    }

    return 0;
}
