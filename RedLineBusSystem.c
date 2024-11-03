#include <stdio.h>
#include <stdlib.h>

int main() {
    char userID[10];
    int varCharges, numCities, numBuses, numTickets;

    // Input User ID and extract required values
    printf("Enter your ID (e.g., 22k-1234): ");
    scanf("%s", userID);
    printf("Enter the ticket base price (varCharges): ");
    scanf("%d", &varCharges);

    // Extract number of cities, buses, and tickets from ID
    numCities = (userID[8] - '0') + 2;            // Last digit + 2
    numBuses = ((userID[7] - '0') * 10) + (userID[8] - '0'); // Last two digits
    numTickets = ((userID[6] - '0') * 100) + ((userID[7] - '0') * 10) + (userID[8] - '0'); // Last three digits

    int totalDiscountElder = 0;
    int totalDiscountChild = 0;

    printf("\nAll Data:\n");
    printf("City   Bus   Passenger   Age   Amount (rupees)\n");

    // For each city, bus, and ticket, calculate price based on age
    for (int city = 1; city <= numCities; city++) {
        for (int bus = 1; bus <= numBuses; bus++) {
            int busTotalSales = 0;
            for (int ticket = 1; ticket <= numTickets; ticket++) {
                int age, ticketPrice;

                printf("Enter age of Passenger %d for City %d Bus %d: ", ticket, city, bus);
                scanf("%d", &age);

                // Calculate ticket price based on age
                if (age >= 60) {
                    ticketPrice = varCharges * 0.7; // 30% discount
                    totalDiscountElder += varCharges - ticketPrice;
                } else if (age < 6) {
                    ticketPrice = varCharges * 0.5; // 50% discount
                    totalDiscountChild += varCharges - ticketPrice;
                } else {
                    ticketPrice = varCharges; // Full price
                }

                busTotalSales += ticketPrice;

                // Print ticket information
                printf("City %d   Bus %d   Passenger %d   %d   %d rupees\n", city, bus, ticket, age, ticketPrice);
            }

            // Print total sales for each bus in each city
            printf("City %d   Bus %d   Total Sales: %d rupees\n", city, bus, busTotalSales);
        }
    }

    // Print total discounts
    printf("\nTotal discount for elders: %d rupees\n", totalDiscountElder);
    printf("Total discount for children: %d rupees\n", totalDiscountChild);

    return 0;
}
