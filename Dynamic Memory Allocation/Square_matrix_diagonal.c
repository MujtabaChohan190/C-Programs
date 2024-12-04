#include <stdio.h>

int main() {
    int n;

    // Input the size of the square matrix
    printf("Enter the size of the square matrix (odd number only): ");
    scanf("%d", &n);

    // Ensure the size is odd
    if (n % 2 == 0) {
        printf("Error: Size must be an odd number.\n");
        return 1;
    }

    // Declare the matrix
    int matrix[n][n];

    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the sums of the diagonals
    int primaryDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        primaryDiagonalSum += matrix[i][i];         // Primary diagonal: elements where row == column
        secondaryDiagonalSum += matrix[i][n - 1 - i]; // Secondary diagonal: elements where row + column == n - 1
    }

    // Display the results
    int totalSum = primaryDiagonalSum + secondaryDiagonalSum;
    printf("Sum of primary diagonal: %d\n", primaryDiagonalSum);
    printf("Sum of secondary diagonal: %d\n", secondaryDiagonalSum);
    printf("Total sum of diagonals: %d\n", totalSum);

    return 0;
}
