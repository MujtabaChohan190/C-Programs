//1. Count Occurrences of Each Character in Inputted Strings (2D Array of Strings)
#include<stdio.h>
#include<string.h>

int main(){
	int i, j, num_slogans, max_length, ascii_value;
	
	//Get number of strings and maximum lengths from the user
	printf("Enter the number of strings: ");
	scanf("%d" ,&num_slogans);
	
	printf("Enter the maximum length of each string: ");
	scanf("%d" , &max_length);
	
	//Clear the input buffer
	getchar();
	
	//Dynamically allocate memory for 2d array of strings
	
	char slogans[num_slogans][max_length + 1]; // +1 to accommodate the null terminator '\0'
	int char_count[256] = {0}; //To store the count of each charcter
	
	//Input slogans from the user
	
	printf("Enter %d strings (max length %d characters)" , num_slogans, max_length);
	for(i=0; i< num_slogans; i++){
		printf("String %d" , i+1);
		fgets(slogans[i] , sizeof(slogans[i]), stdin); //Read User input
		slogans[i][strcspn(slogans[i], "\n")] = '\0'; //Remove newline character if present
	}
	
	//Traverse through each string and count characters
	
	for(i =0; i<num_slogans; i++){
		for(j=0; slogans[i][j] != '\0'; j++){
			char ch = slogans[i][j]; // Get the current character from the string
			ascii_value = (int)ch; // Get the ASCII value of the character
			char_count[ascii_value]++; //Count character occurence
		}
	}
	//Print Character counts
	
	printf("\nCharacter Frequency\n");
	for(i = 0; i<256; i++){
		if(char_count[i]>0){
			printf(" '%c' : %d\n", i , char_count[i]);
		}
	}
	return 0;	
}
