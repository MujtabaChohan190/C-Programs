#include <stdio.h>
#include <string.h>

int main() {
    char strings[5][100] = {"cat", "elephant", "giraffe", "dog", "whale"};
    char longest[100];  // To store the longest string
    strcpy(longest, strings[0]);  // Assume the first string is the longest

    // Find the longest string
    for (int i = 1; i < 5; i++) {
        if (strlen(strings[i]) > strlen(longest)) {
            strcpy(longest, strings[i]);
        }
    }

    printf("The longest string is: %s\n", longest);

    return 0;
}
