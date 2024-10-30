#include<stdio.h>
int main(){
    int rows = 4;
    for(int i = 1; i<=rows; i++){
        for(int k =1;k<= rows - i;k++){
            printf(" ");
        }
        for(int j=1;j<=2 * i -1; j++){
            printf(" %d", j);
        }
        printf("\n");
    }
}
