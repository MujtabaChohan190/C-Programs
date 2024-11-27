#include <stdio.h>
#include <string.h>

// Function to reverse a string using the given logic
void reverseString(const char str[], char reversed_str[]) {
    int length = strlen(str); // Get the length of the input string

    // Create the reversed string
    for (int i = 0; i < length; i++) {
        reversed_str[i] = str[length - 1 - i];
    }

    // Add null terminator at the end of the reversed string
    reversed_str[length] = '\0';
}

int main() {
    char str[100], reversed_str[100];

    // Input from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Reverse the string
    reverseString(str, reversed_str);

    // Print the reversed string
    printf("Reversed string: %s\n", reversed_str);

    return 0;
}
