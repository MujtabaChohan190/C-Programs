// 2468
#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of even values you want: ");
    scanf("%d", &n);
    for(int i = 2; i<=2*n-2; i+=2){
        printf("%d", i);
    }
    return 0;
}