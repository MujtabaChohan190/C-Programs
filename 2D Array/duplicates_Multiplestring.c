#include<stdio.h>
#include<string.h>
//Compressing Function
void compress_word(char input[], char output[], int removed_char[]){
    char current_char;
    int index = 0;
    int count = 0;

    //Array to track seen characters
    int seen[256] = {0}; //Assuming ASCII characters
    //Traverse the input string
    for(int j = 0; input[j]!= '\0'; j++){
        current_char = input[j];
        if(index == 0 || output[index - 1] != current_char){
            if(seen[(unsigned char)current_char] == 0){
                output[index] = current_char; //Add to the output
                seen[(unsigned char)current_char] = 1; //Mark this character as seen
                index++;
            }else{
                count++; //Increment count for removed chars
            }
        }else{
            count++; //Increment count for removed chars incase the previous one and current char is same because current char is now removed and now added to output array
        }
    }
    output[index] = '\0'; //Null terminate the output string
    removed_char[0] = count; //indexed 0 bcs every string removed chars are stored at first index
}
//Main Function
int main(){
    int num_string , max_char;

    //Input the number of strings and maximum length of strings
    printf("Enter the number of strings to input: ");
    scanf("%d", &num_string);

    printf("Enter the maximum number of characters: ");
    scanf("%d", &max_char);

    //Clear the input buffer
    getchar();

    //Declare the arrays
    char string_arr[num_string][max_char + 1]; // +1 for null terminator
    char result[num_string][max_char + 1];
    int removed_char[num_string];

    //Input strings
    for(int i = 0; i<num_string; i++){
        printf("Enter string %d", i+1);
        fgets(string_arr[i], max_char + 1, stdin);
        string_arr[i][strcspn(string_arr[i], "\n")] = '\0'; //Remove the newline character
    }

    //Process each string to compress it
    for(int i = 0 ; i < num_string ; i++){
        compress_word(string_arr[i], result[i], removed_char + i); //Passed the entire removed char to access the first element directly , the function is designed to fill in the count of removed characters in the first postion of passed array
    }
    //Print updated strings and number of removed characters
    for(int i = 0; i<num_string; i++){
        printf("\nString %d (After duplicates removal): %s\n", i+1 , result[i]);
        printf("Characters removed from string %d: %d\n", i+1 , removed_char[i]);
    }
    return 0;
    
}
