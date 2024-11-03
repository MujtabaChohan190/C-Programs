#include <stdio.h>

// Function prototypes
void candidateStatistics(int data[50][4], float GPA[50], int salaryDemand[50], int X, int Y);

int main() {
    int data[50][4];         // Sample data - assuming already populated
    float GPA[50];           // Sample GPA data - assuming already populated
    int salaryDemand[50];    // Sample salary demand data - assuming already populated

    int X, Y;
    printf("Enter X (cumulative score threshold): ");
    scanf("%d", &X);
    printf("Enter Y (salary threshold): ");
    scanf("%d", &Y);

    candidateStatistics(data, GPA, salaryDemand, X, Y);

    return 0;
}

// Function to calculate and print required statistics
void candidateStatistics(int data[50][4], float GPA[50], int salaryDemand[50], int X, int Y) {
    int i, countA = 0, countB = 0, cumulativeScore;
    float sumSalary = 0.0, avgSalary;
    float temp;
    int n = 50;  // number of candidates

    // a) Count candidates with GPA > 3.0 and Analytical test score > 50
    for (i = 0; i < n; i++) {
        if (GPA[i] > 3.0 && data[i][1] > 50) {
            countA++;
        }
    }
    printf("Total number of candidates with GPA > 3.0 and Analytical test score > 50: %d\n", countA);

    // b) Percentage of candidates with cumulative score > X and salary < Y
    for (i = 0; i < n; i++) {
        cumulativeScore = data[i][1] + data[i][2] + data[i][3];
        if (cumulativeScore > X && salaryDemand[i] < Y) {
            countB++;
        }
    }
    float percentageB = ((float)countB / n) * 100;
    printf("Percentage of candidates with cumulative score > %d and salary < %d: %.2f%%\n", X, Y, percentageB);

    // c) Average salary demand
    for (i = 0; i < n; i++) {
        sumSalary += salaryDemand[i];
    }
    avgSalary = sumSalary / n;
    printf("Average salary demand: %.2f\n", avgSalary);

    // d) Median GPA
    // Sort the GPA array for median calculation
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (GPA[i] > GPA[j]) {
                temp = GPA[i];
                GPA[i] = GPA[j];
                GPA[j] = temp;
            }
        }
    }
    float medianGPA;
    if (n % 2 == 0) {
        medianGPA = (GPA[n / 2 - 1] + GPA[n / 2]) / 2;
    } else {
        medianGPA = GPA[n / 2];
    }
    printf("Median GPA: %.2f\n", medianGPA);
}
