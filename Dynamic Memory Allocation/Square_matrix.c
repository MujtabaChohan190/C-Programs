#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, sum = 0;

    // Input the size of the matrix (odd integer)
    printf("Enter the size of the square matrix (odd number): ");
    scanf("%d", &n);

    // Check if n is odd
    if (n % 2 == 0) {
        printf("The size must be an odd number.\n");
        return 1;
    }

    // Dynamically allocate memory for the 2D array
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the sum of the border elements
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Add elements in the border
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                sum += matrix[i][j];
            }
        }
    }

    // Output the calculated sum
    printf("Sum of border elements: %d\n", sum);

    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
