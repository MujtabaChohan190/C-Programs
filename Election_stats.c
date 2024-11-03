#include <stdio.h>

#define AREAS 5
#define CANDIDATES 4

void Check_Winner1(int votes[AREAS][CANDIDATES]) {
    printf("Winners by each area:\n");
    for (int i = 0; i < AREAS; i++) {
        int maxVotes = votes[i][0];
        int winner = 1;
        for (int j = 1; j < CANDIDATES; j++) {
            if (votes[i][j] > maxVotes) {
                maxVotes = votes[i][j];
                winner = j + 1; // candidate number (1-indexed)
            }
        }
        printf("Area %d: Candidate %d\n", i + 1, winner);
    }
}

void Check_Winner2(int votes[AREAS][CANDIDATES]) {
    int totalVotes[CANDIDATES] = {0}; // Array to store total votes for each candidate

    for (int j = 0; j < CANDIDATES; j++) {
        for (int i = 0; i < AREAS; i++) {
            totalVotes[j] += votes[i][j];
        }
    }

    printf("\nTotal votes by each candidate:\n");
    for (int j = 0; j < CANDIDATES; j++) {
        printf("Candidate %d: Total votes %d\n", j + 1, totalVotes[j]);
    }
}

int Check_Winner3(int votes[AREAS][CANDIDATES]) {
    int maxVotes = 0;
    int areaWithMaxVotes = 0;

    for (int i = 0; i < AREAS; i++) {
        int areaVotes = 0;
        for (int j = 0; j < CANDIDATES; j++) {
            areaVotes += votes[i][j];
        }
        if (areaVotes > maxVotes) {
            maxVotes = areaVotes;
            areaWithMaxVotes = i + 1; // area number (1-indexed)
        }
    }

    return areaWithMaxVotes;
}

int main() {
    int votes[AREAS][CANDIDATES] = {
        {192, 48, 206, 37},
        {147, 90, 312, 21},
        {186, 12, 121, 38},
        {114, 21, 408, 39},
        {267, 13, 382, 29}
    };

    // Task (a)
    Check_Winner1(votes);

    // Task (b)
    Check_Winner2(votes);

    // Task (c)
    int maxArea = Check_Winner3(votes);
    printf("\nArea with maximum votes cast: %d\n", maxArea);

    return 0;
}
