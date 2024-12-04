#include <stdio.h>
#include <stdlib.h>

int main() {
    int depth, rows, cols;
    printf("Enter the dimensions (depth, rows, columns): ");
    scanf("%d %d %d", &depth, &rows, &cols);

    // Allocate memory for depth (array of 2D pointers)
    int*** arr = (int***) malloc(depth * sizeof(int**));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Allocate memory for each page (rows)
    for (int i = 0; i < depth; i++) {
        arr[i] = (int**) malloc(rows * sizeof(int*));
        if (arr[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        // Allocate memory for each row (columns)
        for (int j = 0; j < rows; j++) {
            arr[i][j] = (int*) malloc(cols * sizeof(int));
            if (arr[i][j] == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }
        }
    }

    // Input values
    printf("Enter elements of the 3D array:\n");
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                printf("arr[%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    // Output values
    printf("Elements in the 3D array are:\n");
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < rows; j++) {
            free(arr[i][j]); // Free each row
        }
        free(arr[i]); // Free each page
    }
    free(arr); // Free the depth pointers

    return 0;
}
