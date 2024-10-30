//  A
//  A B
//  A B C
//  A B C D
#include<stdio.h>
int main(){
    int rows = 4;
    for(int i= 1; i<=rows; i++){
        for(int j =1; j<=i; j++){
            printf(" %c", 'A' + j -1);
        }
        printf("\n");
    }
}