/*Take the following structures and create functions that perform CRUD (create, read, update delete) operations in a file or multiple files depending on the need based on your understanding. Add a comment that exlpains your choice.

struct player{
char name[20];
char team[20];
};

struct bowl{
char type[10]; // seemer, pacer, spinner// N/A
char arm[5]; //left or right
struct player ply;
};

struct bat{
char type[10]; // top order, middle order, lower order
char handed[8]; //lefty or righty
struct bowl ply2;
};
 suppose that you have to store data for 5 players with at least 3 bowlers. The rest will be N/A.*/


#include <stdio.h>
#include <string.h>

#define FILENAME "players_data.txt"
#define PLAYER_COUNT 5

// Define the structures
struct player {
    char name[20];
    char team[20];
};

struct bowl {
    char type[10]; // seamer, pacer, spinner, or N/A
    char arm[5];   // left or right
    struct player ply;
};

struct bat {
    char type[10];   // top order, middle order, lower order
    char handed[8];  // lefty or righty
    struct bowl ply2;
};

// Function prototypes
void createPlayerData();
void readPlayerData();
void updatePlayerData(int index);
void deletePlayerData(int index);

// Function to create initial player data and save it to a text file
void createPlayerData() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    struct bat players[PLAYER_COUNT] = {
        {"top order", "lefty", {"seamer", "left", {"Player1", "TeamA"}}},
        {"middle order", "righty", {"pacer", "right", {"Player2", "TeamB"}}},
        {"lower order", "lefty", {"spinner", "left", {"Player3", "TeamC"}}},
        {"N/A", "N/A", {"N/A", "N/A", {"Player4", "TeamD"}}},
        {"N/A", "N/A", {"N/A", "N/A", {"Player5", "TeamE"}}},
    };

    for (int i = 0; i < PLAYER_COUNT; i++) {
        fprintf(file, "%s %s %s %s %s %s %s\n",
                players[i].ply2.ply.name,
                players[i].ply2.ply.team,
                players[i].ply2.type,
                players[i].ply2.arm,
                players[i].type,
                players[i].handed);
    }

    fclose(file);
    printf("Initial player data created successfully.\n");
}

// Function to read and display player data from the text file
void readPlayerData() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    struct bat player;
    int i = 0;

    printf("\n--- Player Data ---\n");
    while (fscanf(file, "%s %s %s %s %s %s",
                  player.ply2.ply.name,
                  player.ply2.ply.team,
                  player.ply2.type,
                  player.ply2.arm,
                  player.type,
                  player.handed) == 6) {
        printf("Player %d:\n", i + 1);
        printf("  Name: %s\n", player.ply2.ply.name);
        printf("  Team: %s\n", player.ply2.ply.team);
        printf("  Bowler Type: %s\n", player.ply2.type);
        printf("  Bowler Arm: %s\n", player.ply2.arm);
        printf("  Batsman Type: %s\n", player.type);
        printf("  Batsman Handedness: %s\n\n", player.handed);
        i++;
    }

    fclose(file);
}

// Function to update player data
void updatePlayerData(int index) {
    if (index < 0 || index >= PLAYER_COUNT) {
        printf("Error: Invalid player index.\n");
        return;
    }

    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error: Could not open file for updating.\n");
        return;
    }

    struct bat players[PLAYER_COUNT];
    for (int i = 0; i < PLAYER_COUNT; i++) {
        fscanf(file, "%s %s %s %s %s %s",
               players[i].ply2.ply.name,
               players[i].ply2.ply.team,
               players[i].ply2.type,
               players[i].ply2.arm,
               players[i].type,
               players[i].handed);
    }
    fclose(file);

    printf("Enter updated details for Player %d:\n", index + 1);
    printf("Name: ");
    scanf("%19s", players[index].ply2.ply.name);
    printf("Team: ");
    scanf("%19s", players[index].ply2.ply.team);
    printf("Bowler Type: ");
    scanf("%9s", players[index].ply2.type);
    printf("Bowler Arm: ");
    scanf("%4s", players[index].ply2.arm);
    printf("Batsman Type: ");
    scanf("%9s", players[index].type);
    printf("Batsman Handedness: ");
    scanf("%7s", players[index].handed);

    file = fopen(FILENAME, "w");
    for (int i = 0; i < PLAYER_COUNT; i++) {
        fprintf(file, "%s %s %s %s %s %s\n",
                players[i].ply2.ply.name,
                players[i].ply2.ply.team,
                players[i].ply2.type,
                players[i].ply2.arm,
                players[i].type,
                players[i].handed);
    }
    fclose(file);

    printf("Player %d updated successfully.\n", index + 1);
}

// Function to delete player data (set to "N/A")
void deletePlayerData(int index) {
    if (index < 0 || index >= PLAYER_COUNT) {
        printf("Error: Invalid player index.\n");
        return;
    }

    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error: Could not open file for deleting.\n");
        return;
    }

    struct bat players[PLAYER_COUNT];
    for (int i = 0; i < PLAYER_COUNT; i++) {
        fscanf(file, "%s %s %s %s %s %s",
               players[i].ply2.ply.name,
               players[i].ply2.ply.team,
               players[i].ply2.type,
               players[i].ply2.arm,
               players[i].type,
               players[i].handed);
    }
    fclose(file);

    strcpy(players[index].ply2.ply.name, "N/A");
    strcpy(players[index].ply2.ply.team, "N/A");
    strcpy(players[index].ply2.type, "N/A");
    strcpy(players[index].ply2.arm, "N/A");
    strcpy(players[index].type, "N/A");
    strcpy(players[index].handed, "N/A");

    file = fopen(FILENAME, "w");
    for (int i = 0; i < PLAYER_COUNT; i++) {
        fprintf(file, "%s %s %s %s %s %s\n",
                players[i].ply2.ply.name,
                players[i].ply2.ply.team,
                players[i].ply2.type,
                players[i].ply2.arm,
                players[i].type,
                players[i].handed);
    }
    fclose(file);

    printf("Player %d deleted successfully.\n", index + 1);
}

// Main function to demonstrate CRUD operations
int main() {
    int choice, index;

    do {
        printf("\n--- Player Management System ---\n");
        printf("1. Create Player Data\n");
        printf("2. Read Player Data\n");
        printf("3. Update Player Data\n");
        printf("4. Delete Player Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createPlayerData();
            break;
        case 2:
            readPlayerData();
            break;
        case 3:
            printf("Enter player index to update (0-4): ");
            scanf("%d", &index);
            updatePlayerData(index);
            break;
        case 4:
            printf("Enter player index to delete (0-4): ");
            scanf("%d", &index);
            deletePlayerData(index);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
