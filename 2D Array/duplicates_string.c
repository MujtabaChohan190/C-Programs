#include<stdio.h>
#include<string.h>
int main(){
     int num_string , max_char;
	 char current_char;
	//Input the number of strings and maximum length of string
	printf("Enter the number of strings to input: ");
	scanf("%d", &num_string);

	printf("Enter the maximum number of characters: ");
	scanf("%d" , &max_char);

	//Clear the input buffer
	getchar();

	//Declare the arrays
	char string_arr[num_string][max_char +1]; //To store user input strings(+1 for null terminator)
	char result[num_string][max_char + 1];
	int removed_chars[num_string];

	//Input the string
	for(int i=0;i<num_string;i++){
		printf("Enter the string %d", i+1);
		fgets(string_arr[i], max_char + 1 , stdin);
		string_arr[i][strcspn(string_arr[i], "\n")]= '\0'; //Remove the newline character in the string
	}

	//Traverse through the string and find duplicates
	for(int i=0;i<num_string;i++){
		int char_seen[256] = {0}; //Array to track seen characters using ASII Values
		int index = 0;
		removed_chars[i] = 0; //Initialized removed char array to 0 for each string
		for(int j=0; string_arr[i][j] != '\0';j++){
			current_char = string_arr[i][j];
			if(char_seen[(int)current_char] == 0){ //if the character hasnt been seen
				result[i][index] = current_char; // add it to the result array
				index++;
                char_seen[(int)current_char] = 1; //Mark this particular char in the i string as seen

			}else{
				removed_chars[i]++;
			}			
		}
		result[i][index] = '\0';
	}
	
	//Print updated strings and the number of removed characters
	printf("\nStrings after removing duplicates and characters removed: \n");
	for(int i = 0; i < num_string ; i++){
		printf("String %d (after removal): %s\n", i+1, result[i]);
		printf("Characters removed from string %d: %d\n", i+1 , removed_chars[i]);
	}
	return 0;
}  