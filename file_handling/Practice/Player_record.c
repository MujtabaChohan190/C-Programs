/*Question:

You are required to implement the functionalities of a Player Record Management System for a number of players, each with the following attributes:

Player ID (integer)
Name (string, max length 50)
Highest Kills (integer)
Highest Deaths (integer)
Your program should implement the following functions:

Add a New Player: Append a new player record to the file.
Update a Player's Record: Update an existing player's highest score by searching with the player ID.
Read the Players' Record: Print the highest kills among all the players, print the highest kills per death ratio (float) among all the players.
Create a menu-driven program that allows the user to add and update a player's record, or print the data.

Note:

Use an array of structures, filing, switch statements, and functions.
You are not allowed to use Global variables.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store player information
struct player {
    int playerID;
    char name[50];
    int highestKills;
    int highestDeaths;
};

// Function to add a new player record to the file
void addPlayer() {
    FILE *fp;
    struct player p;

    fp = fopen("Players.txt", "a");
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return;
    }

    printf("Enter player ID: ");
    scanf("%d", &p.playerID);
    printf("Enter player name: ");
    scanf("%s", p.name);
    printf("Enter highest kills: ");
    scanf("%d", &p.highestKills);
    printf("Enter highest deaths: ");
    scanf("%d", &p.highestDeaths);

    // Append the new player record to the file
    fprintf(fp, "%d %s %d %d\n", p.playerID, p.name, p.highestKills, p.highestDeaths);
    printf("Player record added successfully.\n");

    fclose(fp);
}

void updatePlayerRecord() {
    FILE *fp;
    struct player p;
    int playerID, found = 0;
    char choice;

    struct player players[100]; // Array to temporarily hold player records
    int count = 0;              // Counter for the number of records

    // Open the file to read the player records
    fp = fopen("Players.txt", "r");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    // Read all records into the array
    while (fscanf(fp, "%d %s %d %d", &p.playerID, p.name, &p.highestKills, &p.highestDeaths) != EOF) {
        players[count++] = p;
    }
    fclose(fp);

    // Update the desired record
    printf("\nEnter the Player ID to update: ");
    scanf("%d", &playerID);

    for (int i = 0; i < count; i++) {
        if (players[i].playerID == playerID) {
            found = 1;
            printf("\nPlayer Found:\n");
            printf("ID: %d, Name: %s, Highest Kills: %d, Highest Deaths: %d\n", players[i].playerID, players[i].name, players[i].highestKills, players[i].highestDeaths);

            printf("\nUpdate highest kills or deaths? (k/d): ");
            scanf(" %c", &choice);

            if (choice == 'k' || choice == 'K') {
                printf("Enter new highest kills: ");
                scanf("%d", &players[i].highestKills);
                printf("Highest kills updated.\n");
            } else if (choice == 'd' || choice == 'D') {
                printf("Enter new highest deaths: ");
                scanf("%d", &players[i].highestDeaths);
                printf("Highest deaths updated.\n");
            } else {
                printf("Invalid choice.\n");
            }
            break; // Exit loop after finding the player
        }
    }

    if (!found) {
        printf("Player with ID %d not found.\n", playerID);
        return;
    }

    // Reopen the file in write mode to update all records
    fp = freopen("Players.txt", "w", fp);  // Reopen the file in write mode
    if (fp == NULL) {
        printf("File cannot be reopened.\n");
        return;
    }

    // Write updated records back to the file
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %d %d\n", players[i].playerID, players[i].name, players[i].highestKills, players[i].highestDeaths);
    }
    fclose(fp);

    printf("Record updated successfully.\n");
}

// Function to read player records and find specific statistics
void readPlayerRecords() {
    FILE *fp;
    struct player p, highestKillsPlayer;
    int totalMatches;
    float highestKillDeathRatio = 0.0;

    fp = fopen("Players.txt", "r");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\nAll Player Records:\n");
    while (fscanf(fp, "%d %s %d %d", &p.playerID, p.name, &p.highestKills, &p.highestDeaths) != EOF) {
        printf("ID: %d, Name: %s, Highest Kills: %d, Highest Deaths: %d\n", p.playerID, p.name, p.highestKills, p.highestDeaths);

        // Determine player with the highest kills
        if (p.highestKills > highestKillsPlayer.highestKills || highestKillsPlayer.playerID == 0) {
            highestKillsPlayer = p;
        }

        // Determine player with the highest kill-to-death ratio
        if (p.highestDeaths > 0) {
            float killDeathRatio = (float)p.highestKills / p.highestDeaths;
            if (killDeathRatio > highestKillDeathRatio || highestKillsPlayer.playerID == 0) {
                highestKillDeathRatio = killDeathRatio;
                highestKillsPlayer = p;
            }
        }
    }

    printf("\nPlayer with the highest kills:\n");
    printf("ID: %d, Name: %s, Highest Kills: %d, Highest Deaths: %d\n", highestKillsPlayer.playerID, highestKillsPlayer.name, highestKillsPlayer.highestKills, highestKillsPlayer.highestDeaths);

    printf("\nPlayer with the highest kill-to-death ratio:\n");
    printf("ID: %d, Name: %s, Highest Kills: %d, Highest Deaths: %d, Kill/Death Ratio: %.2f\n",
           highestKillsPlayer.playerID, highestKillsPlayer.name, highestKillsPlayer.highestKills,
           highestKillsPlayer.highestDeaths, highestKillDeathRatio);

    fclose(fp);
}

// Main function with menu options
int main() {
    int choice;

    while (1) {
        printf("\n--- Player Record Management ---\n");
        printf("1. Add a New Player\n");
        printf("2. Update a Player's Record\n");
        printf("3. Read the Players' Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPlayer();
                break;
            case 2:
                updatePlayerRecord();
                break;
            case 3:
                readPlayersRecord();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
