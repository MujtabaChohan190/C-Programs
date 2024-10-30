// 1234
// 123
// 12
// 1
#include <stdio.h>

int main() {
    int rows = 4; // Adjust the number of rows as needed

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i + 1; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}