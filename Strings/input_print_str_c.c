#include<stdio.h>
int main(){
	int i = 0;
	char str[5]; // Array can hold 4 characters + 1 null terminator
	for(i=0 ; i < 4 ; i++){
		scanf(" %c" , &str[i] );
		
	}
	str[4] = '\0';  // Null-terminate the string at index 4
	// Output the string
  printf("%s", str);
    
  return 0;
}
