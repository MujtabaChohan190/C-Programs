#include<stdio.h>

int main(){
    int UID = 0;
    int ID = 512;
    int input, course;
    int selected = 0;  // Initialize selected to indicate no course is chosen yet
    int exit;

    // User enters the correct registration ID
    do{
        printf("Enter the registration ID: ");
        scanf("%d", &UID);
    } while(UID != ID);  // Corrected the loop condition

    printf("Welcome User\n");
    printf("1: Register for courses\n");
    printf("2: View Student Details\n");
    printf("3: Exit the system\n");
    printf("Choose between 1 to 3 Options:\n");
    scanf("%d", &input);  // Corrected scanf format

    // Validate the input
    if(input < 1 || input > 3){
        printf("Enter a valid option\n");
        return 1;  // Early exit for invalid input
    }

    switch(input){
        case 1: 
            printf("Which course do you want to enroll in?\n");
            printf("Select 1 for PF, Select 2 for DSA, Select 3 for DBMS\n");
            scanf("%d", &course);

            if(course < 1 || course > 3){
                printf("Enter a valid course option\n");
                return 1;  // Early exit for invalid course option
            }
            
            switch(course){
                case 1:
                    printf("You have enrolled for PF\n");
                    selected = course;
                    break;
                case 2:
                    printf("You have enrolled for DSA\n");
                    selected = course;
                    break;
                case 3:
                    printf("You have enrolled for DBMS\n");
                    selected = course;
                    break;
            }
            break;
            
        case 2:
            // Ensure the user has selected a course
            if (selected == 0) {
                printf("No course selected. Please register for a course first.\n");
            } else {
                printf("Your student record is being shown\n");
                switch(selected){
                    case 1:
                        printf("Name: Mujtaba\nRoll no: 24k-0531\nSection: BCS-1D Course: PF\n");
                        break;
                    case 2:
                        printf("Name: Mujtaba\nRoll no: 24k-0531\nSection: BCS-1D Course: DSA\n");
                        break;
                    case 3:
                        printf("Name: Mujtaba\nRoll no: 24k-0531\nSection: BCS-1D Course: DBMS\n");
                        break;
                }
            }
            break;
        
        case 3:
            printf("Enter any number to exit:\n");
            scanf("%d", &exit);  // Fixed `printf` and `scanf` usage
            break;
    }

    printf("Goodbye\n");
    return 0;
}
