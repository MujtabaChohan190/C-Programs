#include<stdio.h>
int main(){
    int rows = 4;
    for(int i = 1; i<=rows; i++){
        for(int j = 0; j<= rows - 1; j++){
            printf(" ");
        }
        for(int k = 1; k<=i; k++){
            printf(" %c", 'A' + i - 1);
        }
        printf("\n");
    }
}