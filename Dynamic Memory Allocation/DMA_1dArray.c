
//This code dynamically allocate size for 1d array.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of the 1D array: ");
    scanf("%d", &n);

    // Allocate memory for n integers
    int* arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input values
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Output values
    printf("Elements in the array are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);
    return 0;
}
