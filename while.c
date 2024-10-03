/*Which loop system would be better for user input. Justify your answer by creating a program
that takes a value and adds it to a variable and prints it repeatedly until the user enters a zero
value.*/
#include<stdio.h>


int main() {
    int sum = 0;
    int num ;
    
    while(num!=0)
    {

        printf("Enter a value : ");
        scanf("%d" , &num);
        sum = num + sum;
    }
    printf("The sum is %d" , sum);
    return 0;
}

