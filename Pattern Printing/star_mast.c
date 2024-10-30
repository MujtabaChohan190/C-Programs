#include<stdio.h>
int main(){
    int rows = 4;
    for(int i = 1; i<= rows; i++){ //Rows
        for(int j = 1; j<= rows - i; j++){ //loop for printing spaces
            printf(" ");
        }
        for(int k =1; k<=i; k++){
            printf("*");
        }
        printf("\n");
    }
}