#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate email
int validateEmail(char* email) { // It passes the memory address of the string, enabling efficient traversal and validation. Otherwise , we would always have to write string and do other lengthy steps
    if (email == NULL || strlen(email) == 0) { //email== NULL  checks if the pointer email itself is invalid (i.e., points to nothing). A valid pointer could still point to an empty string, so strlen(email) = 0 , condition ensures the content of the string is not empty.
        return 0;
    }

    int atCount = 0;
    char* atPosition = NULL; 
    char* dotPosition = NULL; //with the help of pointer returning NULL  , we got to know that dotPosition has nothing stored. This makes it easy to check the relevant positons .

    // Traverse the email to check criteria
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atCount++;
            atPosition = &email[i];
        } else if (email[i] == '.' && atPosition != NULL) {
            dotPosition = &email[i];
        }
    }

    // Validate criteria:
    // - Only one '@' symbol
    // - A dot exists after the '@' symbol
    // - Email is not empty
    if (atCount == 1 && dotPosition != NULL && dotPosition > atPosition) {
        return 1; // Valid email
    }

    return 0; // Invalid email
}

int main() {
    char* email;
    int size;

    // Prompt user for email size
    printf("Enter the maximum size of your email: ");
    scanf("%d", &size);

    // Allocate memory dynamically based on input size
    email = (char*)malloc((size + 1) * sizeof(char)); // +1 for null terminator

    if (email == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Get the email address from the user
    printf("Enter the email address: ");
    scanf(" %[^\n]", email);

    // Validate the email
    if (validateEmail(email)) { //Passed email only  because  , email is an array and array when written points directly to 1st element
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    // Free dynamically allocated memory
    free(email);

    return 0;
}
