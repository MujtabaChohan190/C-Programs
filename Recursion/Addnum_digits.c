// Write a recursive function that calculates the sum of digits of a number. For example, if
// the input is 123, the output should be 6.

#include <stdio.h>

int sumOfDigits(int n) {
    // Base case: if the number is 0, return 0
    if (n == 0)
        return 0;
    // Recursive case: add the last digit to the sum of the rest of the digits
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Ensure the number is positive for simplicity
    if (num < 0) {
        num = -num;
    }
    
    // Calculate and display the sum of digits
    printf("The sum of digits is: %d\n", sumOfDigits(num));
    
    return 0;
}
