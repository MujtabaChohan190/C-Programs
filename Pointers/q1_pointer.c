/*1. Write a program to print the address of a variable. Use this address to get the 
value of the variable.*/

#include<stdio.h>
int main(){
    int var = 10;
    int *ptr = &var;
    printf("Address of variable is : %p\n", ptr);
    printf("The value at the corresponding address is: %d", *ptr);
    return 0;
}