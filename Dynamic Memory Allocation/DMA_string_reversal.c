//Write a program to dynamically allocate memory for a 2D array of strings. Input the strings from the user and then reverse the order of strings using the swapping method. Display the reversed 2D array.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char str[]) {
    int start = 0;               // Start index
    int end = strlen(str) - 1;   // End index
    char temp;                   // Temporary variable for swapping

    // Swap characters from start and end until the middle is reached
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int rows;

    // Input the number of strings
    printf("Enter the number of strings: ");
    scanf("%d", &rows);

    // Dynamically allocate memory for an array of char pointers (2D array)
    char **strings = (char **)malloc(rows * sizeof(char *));
    if (strings == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit if memory allocation fails
    }

    // Input each string's size and allocate memory accordingly
    for (int i = 0; i < rows; i++) {
        int charCount;
        printf("Enter the number of characters for string %d: ", i + 1);
        scanf("%d", &charCount);

        strings[i] = (char *)malloc((charCount + 1) * sizeof(char)); // +1 for null terminator
        if (strings[i] == NULL) {
            printf("Memory allocation failed for string %d.\n", i + 1);
            return 1; // Exit if memory allocation fails
        }

        printf("Enter string %d: ", i + 1);
        scanf(" %[^\n]", strings[i]); // Input string
    }

    // Reverse each string
    for (int i = 0; i < rows; i++) {
        reverseString(strings[i]);
    }

    // Output reversed strings
    printf("\nReversed Strings:\n");
    for (int i = 0; i < rows; i++) {
        printf("%s\n", strings[i]);
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(strings[i]); // Free memory for each string
    }
    free(strings); // Free memory for the array of pointers

    return 0;
}

