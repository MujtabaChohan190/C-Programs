// Write a program to dynamically allocate memory for 2, 2D arrays of size m×n. Input the
// dimensions m and n and the elements of the matrices, then find the multiplication in a
// function by passing reference of the matrices.

#include <stdio.h>
#include <stdlib.h>

// Function to multiply two matrices
void multiplyMatrices(int **mat1, int **mat2, int **result, int m, int n, int p) {
    // Initialize result matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0; // Initialize to 0
            for (int k = 0; k < n; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int m, n, p;

    // Input dimensions of matrices
    printf("Enter the dimensions of the first matrix (m x n): ");
    scanf("%d %d", &m, &n);

    printf("Enter the number of columns for the second matrix (p): ");
    scanf("%d", &p);

    // Dynamically allocate memory for the first matrix
    int **mat1 = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        mat1[i] = (int *)malloc(n * sizeof(int));
    }

    // Dynamically allocate memory for the second matrix
    int **mat2 = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat2[i] = (int *)malloc(p * sizeof(int));
    }

    // Dynamically allocate memory for the result matrix
    int **result = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        result[i] = (int *)malloc(p * sizeof(int));
    }

    // Input elements of the first matrix
    printf("\nEnter elements of the first matrix (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("mat1[%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input elements of the second matrix
    printf("\nEnter elements of the second matrix (%d x %d):\n", n, p);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("mat2[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    // Call the function to multiply matrices
    multiplyMatrices(mat1, mat2, result, m, n, p);

    // Output the result matrix
    printf("\nResultant Matrix (%d x %d):\n", m, p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(mat1[i]);
    }
    free(mat1);

    for (int i = 0; i < n; i++) {
        free(mat2[i]);
    }
    free(mat2);

    for (int i = 0; i < m; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
