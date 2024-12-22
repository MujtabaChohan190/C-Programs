#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to concatenate two strings using DMA
char* concatenateStrings(char* str1, char* str2) {
    // Calculate the total length of the concatenated string
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int totalLen = len1 + len2 + 1;

    // Allocate memory for the concatenated string
    char* result = (char*)malloc(totalLen * sizeof(char));
    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program if memory allocation fails
    }

    // Copy the first string into result
    strcpy(result, str1);

    // Concatenate the second string to result
    strcat(result, str2);

    return result; // Return the concatenated string
}

int main() {
    char temp[100];
    char* str1;
    char* str2;
    char* concatenated;

    // Input the first string
    printf("Enter the first string: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0'; // Remove trailing newline
    str1 = (char*)malloc((strlen(temp) + 1) * sizeof(char)); // Allocate memory
    strcpy(str1, temp); // Copy the input into str1

    // Input the second string
    printf("Enter the second string: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0'; // Remove trailing newline
    str2 = (char*)malloc((strlen(temp) + 1) * sizeof(char)); // Allocate memory
    strcpy(str2, temp); // Copy the input into str2

    // Concatenate the strings
    concatenated = concatenateStrings(str1, str2);

    // Display the concatenated string
    printf("Concatenated String: %s\n", concatenated);

    // Free dynamically allocated memory
    free(str1);
    free(str2);
    free(concatenated);

    return 0;
}
