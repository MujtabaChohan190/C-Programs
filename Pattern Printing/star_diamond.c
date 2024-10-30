//    *
//   ***
//  *****
// *******
//  *****
//   ***
//    *
#include<stdio.h>
int main(){
    int n;
    printf("Enter no of lines: ");
    scanf("%d", &n);
    int nsp = n/2; //with 7 lines , its answer would be 3 , so there will be 3 spaces on first line 
    int nst = 1; //Always pyramid will have one star at first line
    int middle_line = n/2 + 1;
    for(int i=1; i<=n;i++){ //Rows
        for(int k = 1; k<=nsp; k++){ //Spaces
            printf(" ");     
        }
        for(int j =1; j<=nst; j++){
            printf("*");
        }
        if(i < middle_line){
            nsp--;
            nst+=2;
        }else{
            nsp++;
            nst-=2;
        }
        printf("\n");
    }
    return  0;
}