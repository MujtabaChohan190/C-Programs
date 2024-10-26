#include <stdio.h>

int main() {
    // Declare and initialize a 2D array
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Access and print the element at the 2nd row, 3rd column
    printf("Element at arr[1][2] = %d\n", arr[1][2]);  // Output: 7
    
    // Print the entire 2D array
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
