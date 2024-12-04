
// Question:
// Define a structure that holds information about a student's name, roll number, and marks in five subjects. Write a program that allows the user to select an option from a menu:

// Add student details to a file.
// Display all student details from the file.
// Calculate the total marks, percentage, and grades of all students and write the results into a new file.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
struct student {
    char name[50];
    int rollNumber;
    int marks[5];
};

// Function to add student details to a file
void addStudent() {
    FILE *fp;
    struct student std;

    fp = fopen("Students.txt", "a");
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return;
    }

    printf("Enter student name: ");
    scanf("%s", std.name);
    printf("Enter roll number: ");
    scanf("%d", &std.rollNumber);
    printf("Enter marks in 5 subjects: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &std.marks[i]);
    }

    fprintf(fp, "%s %d %d %d %d %d %d\n", std.name, std.rollNumber, std.marks[0], std.marks[1], std.marks[2], std.marks[3], std.marks[4]);
    printf("Student details added successfully.\n");

    fclose(fp);
}

// Function to display all student details from the file
void displayStudents() {
    FILE *fp;
    struct student std;

    fp = fopen("Students.txt", "r");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    while (fscanf(fp, "%s %d %d %d %d %d %d", std.name, &std.rollNumber, &std.marks[0], &std.marks[1], &std.marks[2], &std.marks[3], &std.marks[4]) != EOF) {
        printf("Name: %s, Roll Number: %d, Marks: %d %d %d %d %d\n",
               std.name, std.rollNumber, std.marks[0], std.marks[1], std.marks[2], std.marks[3], std.marks[4]);
    }

    fclose(fp);
}

// Function to calculate and save total marks, percentage, and grades
void calculateResults() {
    FILE *fp, *out;
    struct student std;

    fp = fopen("Students.txt", "r");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    out = fopen("Results.txt", "w");
    if (out == NULL) {
        printf("File cannot be opened.\n");
        fclose(fp);
        return;
    }

    printf("\nCalculating results and saving to Results.txt...\n");
    while (fscanf(fp, "%s %d %d %d %d %d %d", std.name, &std.rollNumber, &std.marks[0], &std.marks[1], &std.marks[2], &std.marks[3], &std.marks[4]) != EOF) {
        int total = 0;
        for (int i = 0; i < 5; i++) {
            total += std.marks[i];
        }
        float percentage = total / 5.0;
        char grade;
        if (percentage >= 90) {
            grade = 'A';
        } else if (percentage >= 75) {
            grade = 'B';
        } else if (percentage >= 50) {
            grade = 'C';
        } else {
            grade = 'F';
        }
        fprintf(out, "Name: %s, Roll Number: %d, Total: %d, Percentage: %.2f, Grade: %c\n",
                std.name, std.rollNumber, total, percentage, grade);
    }

    printf("Results saved successfully.\n");

    fclose(fp);
    fclose(out);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Add Student Details\n");
        printf("2. Display Student Details\n");
        printf("3. Calculate and Save Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                calculateResults();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
