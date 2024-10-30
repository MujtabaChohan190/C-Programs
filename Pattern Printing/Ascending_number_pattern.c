// 1 2 3
// 4 5 6
// 7 8 9
#include <stdio.h>

int main() {
    int rows = 3; // Adjust the number of rows as needed
    int num = 1;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("%d ", num++);
        }
        printf("\n");
    }

    return 0;
}