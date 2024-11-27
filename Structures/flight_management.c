// Write a program that uses structures to manage flight information, including flight
// number, departure city, destination city, date, and available seats. Create functionalities
// to book a seat and display flight details.

#include <stdio.h>
#include <string.h>

// Define the structure using typedef
typedef struct {
    int flightNumber;
    char departureCity[50];
    char destinationCity[50];
    char date[15];
    int availableSeats;
} Travel;

// Function to display flight details
void displayFlightDetails(Travel flight) {
    printf("Flight Number: %d\n", flight.flightNumber);
    printf("Departure City: %s\n", flight.departureCity);
    printf("Destination City: %s\n", flight.destinationCity);
    printf("Date: %s\n", flight.date);
    printf("Available Seats: %d\n", flight.availableSeats);
}

// Function to book a seat
void bookSeat(Travel *flight) {
    if (flight->availableSeats > 0) {
        flight->availableSeats--;
        printf("Seat booked successfully! Remaining seats: %d\n", flight->availableSeats);
    } else {
        printf("Sorry, no seats available on this flight.\n");
    }
}

int main() {
    Travel flight1;

    // Input flight details
    printf("Enter flight number: ");
    scanf("%d", &flight1.flightNumber);
    getchar(); // Clear newline character left by scanf
    printf("Enter departure city: ");
    fgets(flight1.departureCity, sizeof(flight1.departureCity), stdin);
    flight1.departureCity[strcspn(flight1.departureCity, "\n")] = '\0'; // Remove newline
    printf("Enter destination city: ");
    fgets(flight1.destinationCity, sizeof(flight1.destinationCity), stdin);
    flight1.destinationCity[strcspn(flight1.destinationCity, "\n")] = '\0'; // Remove newline
    printf("Enter date (DD/MM/YYYY): ");
    fgets(flight1.date, sizeof(flight1.date), stdin);
    flight1.date[strcspn(flight1.date, "\n")] = '\0'; // Remove newline
    printf("Enter number of available seats: ");
    scanf("%d", &flight1.availableSeats);

    // Display flight details
    printf("\n--- Flight Details ---\n");
    displayFlightDetails(flight1);

    // Book a seat
    printf("\nBooking a seat...\n");
    bookSeat(&flight1);

    // Display flight details after booking
    printf("\n--- Updated Flight Details ---\n");
    displayFlightDetails(flight1);

    return 0;
}
