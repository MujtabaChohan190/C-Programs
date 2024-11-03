#include <stdio.h>

int main() {
    int arr[3][3];
    int rowSum[3] = {0};  // Array to store sum of each row
    int maxSum = 0;
    int maxRow = 0;

    // Step I: Populate the array with values from user
    printf("Enter 9 elements for a 3x3 array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Element at arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
            rowSum[i] += arr[i][j];  // Calculate row sum while populating
        }
    }

    // Step II: Find the maximum row sum and its row index
    for (int i = 0; i < 3; i++) {
        if (rowSum[i] > maxSum) {
            maxSum = rowSum[i];
            maxRow = i;
        }
    }

    // Step III: Display the maximum sum and the row that contains it
    printf("\nMaximum row sum is %d found in row %d.\n", maxSum, maxRow);

    // Step IV: Replace values in all rows except maxRow with the maximum sum
    for (int i = 0; i < 3; i++) {
        if (i != maxRow) {
            for (int j = 0; j < 3; j++) {
                arr[i][j] = maxSum;
            }
        }
    }

    // Display the modified array
    printf("\nModified Array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
