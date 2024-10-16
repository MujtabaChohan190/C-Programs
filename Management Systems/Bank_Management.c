#include <stdio.h>

int main() {
    int pin = 531;  // Pre-defined PIN, assumed as your roll number (e.g., 531)
    int enteredPin;
    int balance = 10000;  // Initial balance
    int accountNumber;
    int transferAmount;
    int newPin;
    int option;

    while (1) {
        printf("Enter your PIN: ");
        scanf("%d", &enteredPin);

        // Verify PIN
        if (enteredPin != pin) {
            printf("Invalid PIN. Exiting the program.\n");
            return 0;
        }

        // Show options
        printf("\nOptions:\n");
        printf("1. Check Balance\n");
        printf("2. Transfer to Another Bank\n");
        printf("3. Change PIN\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Option 1: Check balance
                printf("Your current balance is: %d\n", balance);
                break;

            case 2:
                // Option 2: Transfer to another bank
                printf("Enter the account number to transfer to: ");
                scanf("%d", &accountNumber);
                printf("Enter the amount to transfer: ");
                scanf("%d", &transferAmount);

                if (transferAmount > balance) {
                    printf("Amount exceeding the current balance. Try again.\n");
                } else {
                    printf("Re-enter your PIN to confirm the transfer: ");
                    scanf("%d", &enteredPin);

                    // Verify PIN again before transfer
                    if (enteredPin != pin) {
                        printf("Invalid PIN. Exiting the program.\n");
                        return 0;
                    }

                    balance -= transferAmount;
                    printf("Transfer successful! New balance: %d\n", balance);
                }
                break;

            case 3:
                // Option 3: Change PIN
                printf("Enter your current PIN: ");
                scanf("%d", &enteredPin);

                // Verify current PIN
                if (enteredPin != pin) {
                    printf("Invalid PIN. Exiting the program.\n");
                    return 0;
                }

                printf("Enter your new PIN: ");
                scanf("%d", &newPin);
                pin = newPin;  // Update the PIN
                printf("PIN successfully changed.\n");
                break;

            default:
                printf("Invalid option. Try again.\n");
        }

        printf("\n");  // Add a new line for readability before the next loop
    }

    return 0;
}
