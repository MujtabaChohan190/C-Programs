#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for 'n' integers
    int* ptr = (int*) malloc(n * sizeof(int));
    int* p = ptr;

    // Input values into the allocated memory
    for (int i = 1; i <= n; i++) {
        scanf("%d", ptr);
        ptr++;
    }

    // Reset pointer to the beginning of allocated memory
    ptr = p;

    // Output the stored values
    for (int i = 1; i <= n; i++) {
        printf("%d\n", *ptr);
        ptr++;
    }

    // Free the allocated memory
    free(p);

    return 0;
}
