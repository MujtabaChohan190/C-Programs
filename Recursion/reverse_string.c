// Write a recursive function that takes a string as input and returns the reversed string.
#include <stdio.h>
#include <string.h>

void reverseRecursive(char str[], int start, int end) {
    // Base case: stop if the start index is greater or equal to the end index
    if (start >= end) {
        return;
    }
    // Swap the characters at start and end
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call to reverse the inner substring
    reverseRecursive(str, start + 1, end - 1); 
}

int main() {
    char str[100];

    // Input from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character, if present
    str[strcspn(str, "\n")] = '\0';

    reverseRecursive(str, 0, strlen(str) - 1);

    printf("Reversed string: %s\n", str);

    return 0;
}
