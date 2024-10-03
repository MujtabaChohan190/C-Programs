/*Using the above program integrate the number if it is a prime or composite number.*/
#include <stdio.h>
int main(){
    int num;
    int i;
    int not_prime = 0;
    printf("Enter the number to check if its composite or prime number");
    scanf("%d" , &num);
    if (num == 0 || num ==1){
        printf("The number is neither prime or composite.\n");
    }
    for(i=2; i<num;i++){
        if(num%i == 0 && num!=2){
        	not_prime = 1;
        	break;
        }else{
        	not_prime == 0;
        	break;
		}
		if(not_prime == 1){
			printf("The number is composite.\n");
	
			
		}else{
			printf("The number is prime.\n");
		}
		
        
        
    }
    return 0;

}