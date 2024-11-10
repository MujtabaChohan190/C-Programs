#include <stdio.h>
#include <string.h>

struct cricketer {
    char name[50];
    int age;
    int noOfMatches;
    float average;
};

int main() {
    struct cricketer arr[3];
    for (int i = 0; i < 3; i++) {
        printf("Enter name: ");
        fgets(arr[i].name, sizeof(arr[i].name), stdin);

        // Removing the newline character using strcspn
        arr[i].name[strcspn(arr[i].name, "\n")] = '\0';

        printf("Enter age: ");
        scanf("%d", &arr[i].age);
        
        printf("Enter number of matches: ");
        scanf("%d", &arr[i].noOfMatches);
        
        printf("Enter average: ");
        scanf("%f", &arr[i].average);
        
        // Clear the input buffer before the next `fgets` call
        while (getchar() != '\n');
    }

    // Optional: Displaying the entered data
    for (int i = 0; i < 3; i++) {
        printf("\nCricketer %d:\n", i + 1);
        printf("Name: %s\n", arr[i].name);
        printf("Age: %d\n", arr[i].age);
        printf("Matches: %d\n", arr[i].noOfMatches);
        printf("Average: %.2f\n", arr[i].average);
    }

    return 0;
}
