#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*)malloc(3 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        arr[i] = i + 1;
    }

    arr = (int*)realloc(arr, 5 * sizeof(int)); // Resize to hold 5 integers

    for (int i = 3; i < 5; i++) {
        arr[i] = i + 1; // Initialize new elements
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    free(arr); // Free allocated memory
    return 0;
}
