#include <stdio.h>
#include <string.h>

int main() {
    char dna[21]; // To store DNA sequence (up to 20 nucleotides + 1 for null terminator)
    int countA = 0, countG = 0, countC = 0, countT = 0;

    printf("Enter a DNA sequence (up to 20 nucleotides): ");
    scanf("%20s", dna); // Limiting input to 20 characters to avoid overflow

    // Count occurrences of each nucleotide
    for (int i = 0; i < strlen(dna); i++) {
        switch (dna[i]) {
            case 'A':
                countA++;
                break;
            case 'G':
                countG++;
                break;
            case 'C':
                countC++;
                break;
            case 'T':
                countT++;
                break;
            default:
                printf("Invalid character in DNA sequence.\n");
                return 1; // Exit if invalid character found
        }
    }

    // Display histogram
    printf("A: ");
    for (int i = 0; i < countA; i++) {
        printf("* ");
    }
    printf("\n");

    printf("G: ");
    for (int i = 0; i < countG; i++) {
        printf("* ");
    }
    printf("\n");

    printf("C: ");
    for (int i = 0; i < countC; i++) {
        printf("* ");
    }
    printf("\n");

    printf("T: ");
    for (int i = 0; i < countT; i++) {
        printf("* ");
    }
    printf("\n");

    return 0;
}
