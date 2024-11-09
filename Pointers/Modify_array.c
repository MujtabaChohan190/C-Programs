// Write a function that takes an array of integers and doubles each element in the array.
#include <stdio.h>

void doubleArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2;  // Modifying elements in the original array
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    doubleArray(numbers, size);  // Passing array to modify elements
    printf("Doubled array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    return 0;
}

// Arrays are already pointers to the first element, so doubleArray can modify the elements in the original array directly.
