//  A B C D
//  A B C D
//  A B C D
//  A B C D
#include<stdio.h>
int main(){
    int n;
    printf("For how many rows you want an A B C D pattern: ");
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=4; j++){
            printf(" %c", 'A' + j -1);
        }
        printf("\n");
    }
}