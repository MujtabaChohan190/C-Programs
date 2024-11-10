#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    char reversed_str [100];
    int length;

    printf("Input the string: ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str, "\n")] = '\0';
    length = strlen(str);
    
    //Create a reversed string
    for(int i = 0; i< length; i++){
        reversed_str[i] = str[length - 1 - i];       
    }
    reversed_str[length] = '\0';

    //Compare the original and reversed str
    if(strcmp(str , reversed_str) == 0){
        printf("\"%s\" is a palindrome.\n", str);
    }else{
        printf("\"%s\" is not a palindrome.\n", str);

    }
    return 0;  
}