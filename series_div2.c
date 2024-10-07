#include <stdio.h>
int main()
{
    int a = 65536;

    printf("%d\t", a);
    for (int i = 2; i <= 9; i++)
        printf("%d\t", a / i);
}
