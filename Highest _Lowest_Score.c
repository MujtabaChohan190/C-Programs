#include <stdio.h>

int main() {
    int score, highest, lowest, highestPlayer, lowestPlayer, i;

    // Input the first score
    printf("Enter the score of Player 1: ");
    scanf("%d", &score);

    // Initialize highest and lowest with the first player's score
    highest = score;
    lowest = score;
    highestPlayer = 1;
    lowestPlayer = 1;

    // Loop to input the remaining 9 scores and find highest and lowest
    for(i = 2; i <= 10; i++) {
        printf("Enter the score of Player %d: ", i);
        scanf("%d", &score);

        if(score > highest) {
            highest = score;
            highestPlayer = i;
        }
        if(score < lowest) {
            lowest = score;
            lowestPlayer = i;
        }
    }

    // Output the highest and lowest score and which player scored them
    printf("Player %d scored the highest with %d points.\n", highestPlayer, highest);
    printf("Player %d scored the lowest with %d points.\n", lowestPlayer, lowest);

    return 0;
}
