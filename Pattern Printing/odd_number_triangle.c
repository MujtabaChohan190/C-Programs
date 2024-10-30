#include <stdio.h>
int main() {
    int rows = 4; // Adjust the number of rows as needed

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", 2 * j - 1); // Print odd numbers
        }
        printf("\n");
    }

    return 0;
}