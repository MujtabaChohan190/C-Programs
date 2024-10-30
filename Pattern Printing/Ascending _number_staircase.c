// 1 
// 2 2 
// 3 3 3 
// 4 4 4 4

#include<stdio.h>
int main(){
    int rows = 4; // Adjust the number of rows as needed

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}