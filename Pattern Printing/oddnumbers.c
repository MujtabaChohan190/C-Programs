#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of odd values you want: ");
    scanf("%d", &n);
    for(int i = 1; i<=2*n-1; i+=2){
        printf("%d", i);
    }
    return 0;
}