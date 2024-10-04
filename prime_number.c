#include <stdio.h>

int main() {
    int num, i;
    int is_prime = 1;  // Assume the number is prime by default

    // Input
    printf("Enter the number to check if it's a prime number: ");
    scanf("%d", &num);

    // Handle special cases for 0, 1, and 2
    if (num == 0 || num == 1) {
        printf("The number is not prime.\n");
        return 0;
    }

    

    // Check divisibility from 2 to sqrt(num)
    for (i = 2; i < num ; i++) {  // Loop from 2 to num/2
        if (num % i == 0) {
            is_prime = 0;  // Found a divisor, so it's not prime
            break;         // No need to check further
        }
    }

    // Output the result
    if (is_prime == 1) {
        printf("The number is prime.\n");
    } else {
        printf("The number is not prime.\n");
    }

    return 0;
    
}

//The loop starts with i = 2 and iterates while i < n. Since i is not less than n (because i = 2 and n = 2),
//the loop does not run at all. The code inside the loop is skipped entirely. After the loop (which didn't run),
//the program checks the value of not_prime. Since not_prime is still 0 (indicating no divisors were found),
//the program concludes that 2 is a prime number. SO there is no need for special num 2 case indicating prime.

