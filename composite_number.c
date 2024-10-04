#include <stdio.h>

int main() {
    int n, i;
    int is_composite = 0;  // Assume the number is not composite initially

    // Input
    printf("Enter number to check if it's a composite number: ");
    scanf("%d", &n);

    // Handle special cases for numbers <= 1
    if (n == 0 || n == 1) {
        printf("%d is neither prime nor composite.\n", n);
        return 0;
    }

    // Check divisibility from 2 to n/2
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {  // If n is divisible by i, it's composite
            is_composite = 1;
            break;  // No need to check further divisors
        }
    }

    // Output the result
    if (is_composite) {
        printf("%d is a composite number.\n", n);
    } else {
        printf("%d is not a composite number (it's a prime number).\n", n);
    }

    return 0;
}

