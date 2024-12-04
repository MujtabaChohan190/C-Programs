// Write a program to dynamically allocate memory for a string, accepts input from the user, and calculates the length of the string without using the strlen() function.


#include <stdio.h>
#include <stdlib.h>

int stringLength(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    char *str;
    int size;

    // Ask user for the length of the string
    printf("Enter the size of the string: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the string
    str = (char *)malloc((size + 1) * sizeof(char)); // +1 for the null terminator

    if (str == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the string
    printf("Enter the string: ");
    scanf("%s", str);  // Note: Using scanf here; to take multi-word input, use fgets() instead

    // Calculate the string length using our custom function
    int length = stringLength(str);
    printf("The length of the string is: %d\n", length);

    // Free dynamically allocated memory
    free(str);

    return 0;
}
