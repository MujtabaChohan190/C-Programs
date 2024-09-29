#include<stdio.h>

float c2f(float); //Function Prototype

float c2f(float c) //Function Defination
{
	return ((9*c)/5)+32; // C TO F = 9/5*C + 32;
}
int main()
{
	float c = 45;
	printf("Celcius to Frenheit is %f" , c2f(c));
	return 0;
}
