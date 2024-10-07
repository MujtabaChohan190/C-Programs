// • Write a program to print the following series: 1, 2, 3, 5, 8, 13.
#include <stdio.h>
int main()
{
    int a = 1;
    int b = 2, result;
    printf("%d\t%d\t", a, b);
    for (int i = 1; i <= 4; i++)
    {
        result = a + b;
        printf("%d\t", result);
        a = b;
        b = result;
    }
    return 0;
}