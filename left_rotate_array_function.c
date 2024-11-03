#include <stdio.h>

void rotate_left(int arr[], int arrSize) {
    // Store the first element, which will be moved to the end
    int firstElement = arr[0];

    // Shift all elements one position to the left
    for (int i = 0; i < arrSize - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Place the first element at the end
    arr[arrSize - 1] = firstElement;
}

int main() {
    int arr[] = {5, 3, 7, 8, 1, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }

    rotate_left(arr, arrSize);

    printf("\nRotated Array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
