// 1 3 5 7
// 1 3 5 7
// 1 3 5 7
// 1 3 5 7

#include <stdio.h>
int main() {
    int rows = 4; // Adjust the number of rows as needed

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= 4; j++) {
            printf("%d ", 2 * j - 1); // Print odd numbers
        }
        printf("\n");
    }

    return 0;
}