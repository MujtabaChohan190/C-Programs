#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Allocate memory for rows (array of pointers)
    int** arr = (int**) malloc(rows * sizeof(int*));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*) malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    // Input values
    printf("Enter elements of the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Output values
    printf("Elements in the 2D array are:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]); // Free each row
    }
    free(arr); // Free the row pointers
    return 0;
}
