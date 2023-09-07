#include <stdio.h>

int factorial(int n){
    int i,prod=1;
    
    for(i=n;i!=0;i--){
        prod = prod*i;
    }
    return prod;
}

int main(){
    int a,n;
    printf("Enter the number : ");
    scanf("%d",&n);
    a = factorial(n);
    printf("Factorial of %d is : ",n);
    printf("%d",a);
    printf("\n");
    return 0;
}