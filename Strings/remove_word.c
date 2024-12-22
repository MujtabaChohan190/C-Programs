#include <stdio.h>
#include <string.h>

// Function prototype
void removeWordFromString(char str[], char word[], char neww[]);

int main() {
    char str[100] = "Hello world, welcome to the programming world!";
    char word[20] = "world";
    char neww[100];

    printf("Original String: %s\n", str);
    printf("Word to remove: %s\n", word);

    // Call the function
    removeWordFromString(str, word, neww);

    // Print the modified string
    printf("Modified String: %s\n", neww);

    return 0;
}

// Function definition
void removeWordFromString(char str[], char word[], char neww[]) {
    char *position;
    int index = 0;
    int wordLength = strlen(word);

    // Copy the original string into neww initially
    strcpy(neww, str);

    // Find the position of the word in the string
    position = strstr(str, word);

    // If the word is found
    if (position != NULL) {
        // Calculate the index of the word in the original string
        index = position - str;

        // Copy the part of the string before the word
        strncpy(neww, str, index);
        neww[index] = '\0'; // Add a null terminator

        // Append the part of the string after the word
        strcat(neww, position + wordLength);
    }
}
