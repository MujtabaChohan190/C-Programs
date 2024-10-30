//First grasp the logic of typical star pattern , then modify it by adding space through k variable with formula : rows - i and then since we want pfd stars , use formula 2* i - 1 in j loop

#include<stdio.h>
int main(){
    int rows = 4;
    for(int i=1;i<=rows;i++){
        for(int k=1;k<=rows-i;k++){
            printf(" ");
        }
        for(int j = 1; j<= 2 * i - 1; j++){
            printf("*");
        }
        printf("\n");
    }   
}