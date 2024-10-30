#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of rows upon which you want your triangle: ");
    scanf("%d", &n);
    for(int i = 1; i<=n ; i++){
        for(int j = 1; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }
}