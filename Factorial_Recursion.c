#include<stdio.h>

int factorial(int); //Function prototype

int factorial(int n){
	if (n==1 || n==0){
		return 1;
	}
	return factorial(n-1)* n;
}
int main(){
	int a = 3;
	printf("The factorial of %d is %d" , a , factorial(a));
	
}
