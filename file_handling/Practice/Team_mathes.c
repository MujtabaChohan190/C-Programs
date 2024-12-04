/*Here’s the question corresponding to the code provided:

Q: Implement the functionalities of a Team Record Management System for a number of teams, where each team has the following attributes:

Team ID (integer)
Name (string, maximum length 50)
Total Wins (integer)
Total Losses (integer)
Your program should implement the following functions:

Add a New Team: Append a new team's details to a file.
Update a Team's Record: Update an existing team’s record by searching for the team ID in the file and incrementing either the wins or losses by 1.
Read the Team's Record:
Print all team records.
Identify and print:
The team with the highest wins.
The team with the highest win percentage, calculated as:
Win Percentage = (Wins / Total Matches) × 100, where Total Matches = Wins + Losses.
Additional Requirements:

Create a menu-driven program that allows the user to add a team, update a team's record, or display all team details along with the required statistics.
Use an array of structures, file handling, switch statements, and functions.
Do not use global variables.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store team information
struct team {
    int teamID;
    char name[50];
    int wins;
    int losses;
};

// Function to add a new team to the file
void addNewTeam() {
    FILE *fp;
    struct team t;

    fp = fopen("Teams.txt", "a");
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return;
    }

    printf("\nEnter Team ID: ");
    scanf("%d", &t.teamID);
    printf("Enter Team Name: ");
    scanf(" %[^\n]", t.name); // Space to handle strings with spaces
    printf("Enter Total Wins: ");
    scanf("%d", &t.wins);
    printf("Enter Total Losses: ");
    scanf("%d", &t.losses);

    fprintf(fp, "%d %s %d %d\n", t.teamID, t.name, t.wins, t.losses);
    printf("\nTeam added successfully!\n");

    fclose(fp);
}

void updateTeamRecord() {
    FILE *fp;
    struct team t;
    int teamID, found = 0;
    char choice;

    struct team teams[100]; // Array to temporarily hold team records
    int count = 0;          // Counter for the number of records

    fp = fopen("Teams.txt", "r");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    // Read all records into the array
    while (fscanf(fp, "%d %s %d %d", &t.teamID, t.name, &t.wins, &t.losses) != EOF) {
        teams[count++] = t;
    }
    fclose(fp);

    // Update the desired record
    printf("\nEnter the Team ID to update: ");
    scanf("%d", &teamID);

    for (int i = 0; i < count; i++) {
        if (teams[i].teamID == teamID) {
            found = 1;
            printf("\nTeam Found:\n");
            printf("ID: %d, Name: %s, Wins: %d, Losses: %d\n", teams[i].teamID, teams[i].name, teams[i].wins, teams[i].losses);

            printf("\nUpdate wins or losses? (w/l): ");
            scanf(" %c", &choice);

            if (choice == 'w' || choice == 'W') {
                teams[i].wins++;
                printf("Wins incremented by 1.\n");
            } else if (choice == 'l' || choice == 'L') {
                teams[i].losses++;
                printf("Losses incremented by 1.\n");
            } else {
                printf("Invalid choice.\n");
            }
            break; // Exit loop after finding the team
        }
    }

    if (!found) {
        printf("Team with ID %d not found.\n", teamID);
        return;
    }

    // Reopen the file in write mode to update all records
    fp = freopen("Teams.txt", "w", fp);
    if (fp == NULL) {
        printf("File cannot be reopened.\n");
        return;
    }

    // Write updated records back to the file
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %d %d\n", teams[i].teamID, teams[i].name, teams[i].wins, teams[i].losses);
    }
    fclose(fp);

    printf("Record updated successfully.\n");
}

// Function to read team records and find specific statistics
void readTeamRecords() {
    FILE *fp;
    struct team t, highestWinsTeam, highestWinPercentageTeam;
    int totalMatches;
    float highestWinPercentage = 0.0;

    fp = fopen("Teams.txt", "r");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\nAll Team Records:\n");
    while (fscanf(fp, "%d %s %d %d", &t.teamID, t.name, &t.wins, &t.losses) != EOF) {
        printf("ID: %d, Name: %s, Wins: %d, Losses: %d\n", t.teamID, t.name, t.wins, t.losses);

        /* Determine team with highest wins
         Check if this team has a higher win percentage than the current highest
         First condition: winPercentage > highestWinPercentage
         Second condition: highestWinPercentageTeam.teamID == 0
         Purpose of second condition: This ensures that during the first iteration, 
         when no team has been assigned to highestWinPercentageTeam yet, 
         the first team's data gets assigned as the highest by default.*/

        if (t.wins > highestWinsTeam.wins || highestWinsTeam.teamID == 0) {
            highestWinsTeam = t;
        }

        // Determine team with highest win percentage
        totalMatches = t.wins + t.losses;
        if (totalMatches > 0) {
            float winPercentage = (float)t.wins / totalMatches * 100;
            if (winPercentage > highestWinPercentage || highestWinPercentageTeam.teamID == 0) {
                highestWinPercentage = winPercentage;
                highestWinPercentageTeam = t;
            }
        }
    }
    printf("\nTeam with the highest wins:\n");
    printf("ID: %d, Name: %s, Wins: %d, Losses: %d\n", highestWinsTeam.teamID, highestWinsTeam.name, highestWinsTeam.wins, highestWinsTeam.losses);

    printf("\nTeam with the highest win percentage:\n");
    printf("ID: %d, Name: %s, Wins: %d, Losses: %d, Win Percentage: %.2f%%\n",
           highestWinPercentageTeam.teamID, highestWinPercentageTeam.name,
           highestWinPercentageTeam.wins, highestWinPercentageTeam.losses, highestWinPercentage);

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Add New Team\n");
        printf("2. Update Team's Record\n");
        printf("3. Read Team Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewTeam();
                break;
            case 2:
                updateTeamRecord();
                break;
            case 3:
                readTeamRecords();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
