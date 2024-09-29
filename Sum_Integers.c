// write a C program that sums a sequence of integers. The first integer entered specifies how many numbers will be summed.
#include<stdio.h>
int count , num;
int sum , i = 0;
int main()
{
	printf("Enter the number of integers to sum: ");
	scanf("%d" , &count);
	
	for(i=0; i<count; i++){
		printf("Enter the number: \n");
		scanf("%d" , &num);
		sum+=num; //Same as sum = sum + num
		
	}
	printf("The sum is %d\n" , sum);
	return 0;
}

