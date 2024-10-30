#include <stdio.h>

int main() {
    int rows = 4; // Adjust the number of rows as needed
    int num = 1;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", num++);
        }
        printf("\n");
    }

    return 0;
}