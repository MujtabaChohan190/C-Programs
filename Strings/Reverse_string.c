#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char str[]) {
    int length = strlen(str); // Get the length of the string
    int start = 0;           // Start index
    int end = length - 1;    // End index
    char temp;               // Temporary variable for swapping

    // Swap characters from start and end until the middle is reached
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Main function
int main() {
    char str[100];
    
    // Input from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character, if present
    str[strcspn(str, "\n")] = '\0';
    
    // Reverse the string
    reverseString(str);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
