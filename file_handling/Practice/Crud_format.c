#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[20];
    int age;
    float gpa;
};

// Function to insert a new record
void insertRecord() {
    FILE *fp;
    struct student std;

    fp = fopen("Student.txt", "a");
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return;
    }

    printf("Enter student name, age, and GPA: ");
    scanf("%s %d %f", std.name, &std.age, &std.gpa);

    fprintf(fp, "%s %d %.2f\n", std.name, std.age, std.gpa);
    printf("Record inserted successfully.\n");

    fclose(fp);
}

// Function to display all records
void displayRecords() {
    FILE *fp;
    struct student std;

    fp = fopen("Student.txt", "r");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    while (fscanf(fp, "%s %d %f", std.name, &std.age, &std.gpa) != EOF) {
        printf("Name: %s, Age: %d, GPA: %.2f\n", std.name, std.age, std.gpa);
    }

    fclose(fp);
}

// Function to update a record
void updateRecord() {
    FILE *fp;
    struct student std[100];
    char target[20];
    int count = 0, found = 0;

    fp = fopen("Student.txt", "r+");
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return;
    }

    // Read all records into memory
    while (fscanf(fp, "%s %d %f", std[count].name, &std[count].age, &std[count].gpa) != EOF) {
        count++;
    }

    printf("Enter the name of the student to update: ");
    scanf("%s", target);

    // Update the record in memory
    for (int i = 0; i < count; i++) {
        if (strcmp(std[i].name, target) == 0) {
            printf("Enter new age and GPA: ");
            scanf("%d %f", &std[i].age, &std[i].gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    } else {
        // Rewrite all records back to the file
        freopen("Student.txt", "w", fp);
        for (int i = 0; i < count; i++) {
            fprintf(fp, "%s %d %.2f\n", std[i].name, std[i].age, std[i].gpa);
        }
        printf("Record updated successfully.\n");
    }

    fclose(fp);
}

// Function to delete a record
void deleteRecord() {
    FILE *fp;
    struct student std[100];
    char target[20];
    int count = 0, found = 0;

    fp = fopen("Student.txt", "r+");
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return;
    }

    // Read all records into memory
    while (fscanf(fp, "%s %d %f", std[count].name, &std[count].age, &std[count].gpa) != EOF) {
        count++;
    }

    printf("Enter the name of the student to delete: ");
    scanf("%s", target);

    // Mark record for deletion in memory
    for (int i = 0; i < count; i++) {
        if (strcmp(std[i].name, target) == 0) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                std[j] = std[j + 1];
            }
            count--;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    } else {
        // Rewrite all records back to the file
        freopen("Student.txt", "w", fp);
        for (int i = 0; i < count; i++) {
            fprintf(fp, "%s %d %.2f\n", std[i].name, std[i].age, std[i].gpa);
        }
        printf("Record deleted successfully.\n");
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert Record\n");
        printf("2. Display Records\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
