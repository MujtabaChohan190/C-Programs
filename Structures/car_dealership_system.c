// Create a structure to store details about cars in a dealership, including make, model,
// year, price, and mileage. Write a program that allows users to add new cars, display a
// list of available cars, and search for cars by make or model.

#include <stdio.h>
#include <string.h>

// Define a structure for car details
typedef struct {
    char make[50];
    char model[50];
    int year;
    float price;
    int mileage;
} Car;

void addCar(Car cars[], int *count) {  //We took count address as we may need to add car to a particular count of car array . 
    if (*count >= 100) { // Limiting to a maximum of 100 cars
        printf("Maximum car limit reached. Cannot add more cars.\n");
        return;
    }

    printf("Enter car details:\n");
    printf("Make: ");
    scanf("%s", cars[*count].make);
    printf("Model: ");
    scanf("%s", cars[*count].model);
    printf("Year: ");
    scanf("%d", &cars[*count].year);
    printf("Price: ");
    scanf("%f", &cars[*count].price);
    printf("Mileage: ");
    scanf("%d", &cars[*count].mileage);

    (*count)++;
    printf("Car added successfully!\n");
}


void displayCars(Car cars[], int count) {
    if (count == 0) {
        printf("No cars available in the dealership.\n");
        return;
    }

    printf("\nList of Available Cars:\n");

    for (int i = 0; i < count; i++) {
        printf("Car %d:\n", i + 1);
        printf("Make: %s\n", cars[i].make);
        printf("Model: %s\n", cars[i].model);
        printf("Year: %d\n", cars[i].year);
        printf("Price: $%.2f\n", cars[i].price);
        printf("Mileage: %d km\n", cars[i].mileage);
    }
}

void searchCar(Car cars[], int count) {
    if (count == 0) {
        printf("No cars available in the dealership.\n");
        return;
    }

    char searchQuery[50];
    printf("Enter make or model to search for: ");
    scanf("%s", searchQuery);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(cars[i].make, searchQuery) == 0 || strcmp(cars[i].model, searchQuery) == 0) {
            printf("\nCar Found:\n");
            printf("Make: %s\n", cars[i].make);
            printf("Model: %s\n", cars[i].model);
            printf("Year: %d\n", cars[i].year);
            printf("Price: $%.2f\n", cars[i].price);
            printf("Mileage: %d km\n", cars[i].mileage);
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found with make or model '%s'.\n", searchQuery);
    }
}

int main() {
    Car cars[100]; // Array to store up to 100 cars
    int count = 0; 
    int choice;

    while (1) {
        printf("\nCar Dealership Management System\n");
        printf("1. Add a New Car\n");
        printf("2. Display Available Cars\n");
        printf("3. Search for Cars by Make or Model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar(cars, &count);
                break;
            case 2:
                displayCars(cars, count);
                break;
            case 3:
                searchCar(cars, count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
