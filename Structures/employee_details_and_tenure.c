/*Write a program that contains a structure named Employee which contains the following
data members:
● employeeCode
● employeeName
● dateOfJoining
Perform the following operations:
1. Define a function that assigns user-defined values to these variables.
2. Create an array of 4 Employee structs and initialize them with user-defined values.
3. Define a function that asks the user to enter the current date, calculates the tenure of
each employee, and checks if the tenure is more than three years. Display the details of
employees with tenure of more than three years and the count of such employees.*/

#include <stdio.h>
#include <time.h>

typedef struct
{
    int employeeCode;         // Declare the type of employeeCode
    char employeeName[50];    // Declare employeeName as an array of characters
    int dateOfJoining[3];     // Format of dd / mm / yy (int array for day, month, year)
} Employee;

void assignEmployeeDetails(Employee *emp)
{
    printf("Enter employee code: ");
    scanf("%d", &emp->employeeCode); // employee code is an int variable and so scanf requires & to store the employee code
    printf("Enter Employee name: ");
    scanf(" %[^\n]", emp->employeeName); // % [^\n] to accept strings with spaces
    printf("Enter date of joining (dd mm yyyy): ");
    scanf("%d %d %d", &emp->dateOfJoining[0], &emp->dateOfJoining[1], &emp->dateOfJoining[2]);
}

void checkTenure(Employee employees[], int size)
{
    int currentDate[3]; // Format: [day, month, year]
    int count = 0;

    printf("\nEnter Current Date (dd mm yyyy): ");
    scanf("%d %d %d", &currentDate[0], &currentDate[1], &currentDate[2]);
    
    printf("Employees with tenure > 3 years:\n");
    printf("Code\tName\t\tDate of Joining\t\tTenure\n");

    for (int i = 0; i < size; i++)
    {
        int years = currentDate[2] - employees[i].dateOfJoining[2]; // Accessing each employee's details
        int months = currentDate[1] - employees[i].dateOfJoining[1];
        int days = currentDate[0] - employees[i].dateOfJoining[0];

        // Adjusting tenure for incomplete months or days
        if (months < 0 || (months == 0 && days < 0))
        {
            years--; // Decrease years if months are negative or if the anniversary hasn't passed yet
            if (months < 0)
            {
                months += 12; // Recalculate months if negative
            }
            if (days < 0)
            {
                months--;   // Borrow 1 month for negative days
                days += 30; // Approximate the days in a month
            }
        }

        // Print details of employees with tenure greater than 3 years
        if (years > 3)
        {
            count++;
            printf("%d\t%s\t\t%02d/%02d/%d\t\t%d years\n",
                   employees[i].employeeCode,
                   employees[i].employeeName,
                   employees[i].dateOfJoining[0],
                   employees[i].dateOfJoining[1],
                   employees[i].dateOfJoining[2],
                   years);
        }
    }

    // Display the count of employees with tenure greater than 3 years
    printf("Total employees with tenure > 3 years: %d\n", count);
}

int main()
{
    Employee employee[4]; // Array of 4 employees
    
    // Initializing all 4 employees with user-defined values
    for (int i = 0; i < 4; i++)
    {
        printf("Employee %d\n", i + 1);
        assignEmployeeDetails(&employee[i]); // Passing the address of each employee to the function
    }

    // Calculate tenure and display details of employees with tenure > 3 years
    checkTenure(employee, 4); // Pass the employee array and its size to check tenure

    return 0;
}
