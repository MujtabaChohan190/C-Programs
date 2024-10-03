/*Write a program to check whether a given number is a multiple digit number or not.

1. Example: 123 is a multiple digit number.
2. 6 is not a multiple digit number.*/

#include<stdio.h>
int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d" , &num);
    
    if(num / 10 > 1 )
    {
        printf("%d number is single digit" , num);

    }else{
        printf("%d number is not single digit" , num);
    }
       
}
