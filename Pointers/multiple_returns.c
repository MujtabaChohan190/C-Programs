
#include <stdio.h>

void sumAndProduct(int a, int b, int *sum, int *product) {
    *sum = a + b;       // Store the sum at the address pointed to by `sum`
    *product = a * b;   // Store the product at the address pointed to by `product`
}

int main() {
    int x = 4, y = 5;
    int sum, product;   // Declare regular int variables for sum and product
    sumAndProduct(x, y, &sum, &product);  // Pass the addresses of sum and product
    printf("Sum: %d, Product: %d\n", sum, product);  // Print the values of sum and product
    return 0;
}
