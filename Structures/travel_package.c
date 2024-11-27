// Design a structure to store information about travel packages, including package name,
// destination, duration, cost, and number of seats available. Write a program that allows
// users to book a travel package and display available packages.

#include <stdio.h>
#include <string.h>

// Define the structure to store travel package details
typedef struct {
    char packageName[50];
    char destination[50];
    int duration;  // Duration in days
    float cost;    // Cost in dollars
    int availableSeats; // Number of available seats
} TravelPackage;

// Function to display available travel packages
void displayPackages(TravelPackage packages[], int n) {
    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < n; i++) {
        printf("Package: %s\n", packages[i].packageName);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f\n", packages[i].cost);
        printf("Available Seats: %d\n", packages[i].availableSeats);
    }
}

// Function to book a travel package
void bookPackage(TravelPackage *package) {
    if (package->availableSeats > 0) {
        package->availableSeats--;  // Decrease the available seats by 1
        printf("You have successfully booked the package: %s\n", package->packageName);
    } else {
        printf("Sorry, no available seats for this package.\n");
    }
}

int main() {

    TravelPackage packages[] = {
        {"Beach Paradise", "Hawaii", 7, 1200.50, 10},
        {"Mountain Adventure", "Switzerland", 10, 1500.75, 5},
        {"City Escape", "New York", 5, 800.00, 8},
        {"Cultural Journey", "Japan", 14, 2500.00, 3}
    };
    
    int numPackages = sizeof(packages) / sizeof(packages[0]); // Number of packages

    int choice;
    int packageIndex;
    
    while (1) {
        printf("\nWelcome to the Travel Package Booking System\n");
        printf("1. Display Available Packages\n");
        printf("2. Book a Package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayPackages(packages, numPackages);
                break;
                
            case 2:
                printf("Enter the index of the package you want to book (0 to %d): ", numPackages - 1);
                scanf("%d", &packageIndex);
                
                if (packageIndex >= 0 && packageIndex < numPackages) {
                    bookPackage(&packages[packageIndex]);
                } else {
                    printf("Invalid package index!\n");
                }
                break;
                
            case 3:
                printf("Thank you for using the Travel Package Booking System!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
