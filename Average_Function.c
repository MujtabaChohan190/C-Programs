/*Write a program using function to find average of three numbers.*/

#include<stdio.h>

//Function Protottype
float average(int , int , int); // average function has float datatype and will take integers.

float average(int a , int b , int c) //Function Defination
{ 
	return (a+b+c)/3;	
}

int main()
{
	int a = 3 ,b = 6 , c = 9;
	printf("The average of a , b , c is %f" , average(a,b,c)); // %f is used because it is a floating point number
	return 0;
}

