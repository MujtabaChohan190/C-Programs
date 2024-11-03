#include <stdio.h>

#define N 5  // Define the size of the matrix

// Function to transpose the matrix
void transposeMatrix(int mat[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

// Function to print the matrix
void printMatrix(int mat[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[N][N] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    printf("Original Matrix:\n");
    printMatrix(mat);

    // Transpose the matrix
    transposeMatrix(mat);

    printf("\nTransposed Matrix:\n");
    printMatrix(mat);

    return 0;
}
