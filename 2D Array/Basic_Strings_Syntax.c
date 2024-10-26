#include <stdio.h>

int main() {
    char names[3][20];  // Declare a 2D array for 3 strings, each with a maximum length of 19 characters

    // Input 3 names
    for (int i = 0; i < 3; i++) {
        printf("Enter name %d: ", i + 1);
        scanf("%19s", names[i]);  // Read at most 19 characters for each name
    }

    // Output the names
    printf("The entered names are:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
