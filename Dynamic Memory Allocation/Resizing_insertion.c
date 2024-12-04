#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure
typedef struct {
    int id;
    char name[50];
} Record;

int main() {
    int size, count = 0; // Initial size and count of records
    Record *records;

    // Input the initial size of the structure array
    printf("Enter the initial size of the structure array: ");
    scanf("%d", &size);

    // Allocate memory for the structure array using calloc
    records = (Record *)calloc(size, sizeof(Record));
    if (records == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;
    do {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Add a new record\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Check if resizing is needed
                if (count == size) {
                    size *= 2; // Double the size
                    records = (Record *)realloc(records, size * sizeof(Record));
                    if (records == NULL) {
                        printf("Memory reallocation failed!\n");
                        return 1;
                    }
                    printf("Memory resized. New size: %d\n", size);
                }

                // Add a new record
                printf("Enter ID: ");
                scanf("%d", &records[count].id);
                printf("Enter Name: ");
                scanf(" %[^\n]s", records[count].name); // Read string with spaces
                count++; // Increment the count of records
                break;

            case 2:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 2);

    // Free allocated memory
    free(records);

    return 0;
}
