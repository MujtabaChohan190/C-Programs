#include <stdio.h>

int main() {
    int octal, decimal = 0, remainder, multiplier = 1;

    // Input octal number from user
    printf("Enter an octal number: ");
    scanf("%d", &octal);

    // Convert octal to decimal
    while (octal != 0) {
        remainder = octal % 10;  // Get the last digit of the octal number
        decimal = decimal + remainder * multiplier;  // Add to the result with current multiplier
        multiplier = multiplier * 8;  // Update multiplier (8^n)
        octal = octal / 10;  // Remove the last digit
    }

    // Output the result
    printf("The decimal equivalent is: %d\n", decimal);

    return 0;
}
