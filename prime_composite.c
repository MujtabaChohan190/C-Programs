/*Using the above program integrate the number if it is a prime or composite number.*/
#include <stdio.h>

int main() {
    int num;
    int i;
    int not_prime = 0;

    // Input
    printf("Enter the number to check if it's a composite or prime number: ");
    scanf("%d", &num);

    // Special case for 0 and 1
    if (num == 0 || num == 1) {
        printf("The number is neither prime nor composite.\n");
        return 0;
    }
    if (num == 2) {
        printf("The number is prime.\n");
        return 0;
    }

    // Loop through possible divisors
    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            not_prime = 1;  // Number is divisible by i, so it's composite
            break;          // No need to check further
        }
    }

    // Output the result
    if (not_prime == 1) {
        printf("The number is composite.\n");
    } else {
        printf("The number is prime.\n");
    }

    return 0;
}

