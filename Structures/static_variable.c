// Create a program with a constant that defines the maximum allowable temperature (in
// Celsius). Write a function to compare input temperatures and use a static variable to
// count how many times temperatures exceeded the limit.

#include <stdio.h>

#define MAX_TEMPERATURE 40 

void checkTemperature(float temp) {
    // Static variable to count exceedances
    static int exceedCount = 0;

    if (temp > MAX_TEMPERATURE) {
        exceedCount++;
        printf("Temperature %.2f°C exceeds the maximum allowable limit of %d°C.\n", temp, MAX_TEMPERATURE);
    } else {
        printf("Temperature %.2f°C is within the allowable limit.\n", temp);
    }

    printf("Number of exceedances so far: %d\n", exceedCount);
}

int main() {
    float temperatures[] = {33.5, 47.0, 39.2, 47.7, 38.6};
    int size = sizeof(temperatures) / sizeof(temperatures[0]);

    for (int i = 0; i < size; i++) {
        checkTemperature(temperatures[i]);
    }

    return 0;
}
