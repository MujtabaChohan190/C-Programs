// Create a C program that defines a constant for the conversion factor of meters to
// kilometers. Use a static variable in a function to count how many times the function is
// called.

#include <stdio.h>

#define METERS_TO_KILOMETERS 0.001  // Constant for converting meters to kilometers


double convertToKilometers(int  meters) {
    // Static variable to count the number of function calls
    static int callCount = 0;
    callCount++;
    printf("The convertToKilometers function has been called %d times.\n", callCount);
  
    return meters * METERS_TO_KILOMETERS; // convert meters to kilometers
}

int main() {
    int meters;
    
    printf("Enter the distance in meters: ");
    scanf("%d", &meters);

    // Call the function to convert the input meters to kilometers
    double kilometers = convertToKilometers(meters);
    
    // Display the result
    printf("Distance in kilometers: %.6f\n", kilometers);
    convertToKilometers(1000); 
    convertToKilometers(500);  
    
    return 0;
}
