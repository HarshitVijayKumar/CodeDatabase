#include <stdio.h>
int checkPrime(int);

int main(){
    int n,prime;

    printf("Enter the number :");
    scanf("%d",&n);

    prime = checkPrime(n);

    if (prime==1){
        printf("%d is a Prime Number",n);
    }
    else{
        printf("%d is not a Prime Number",n);
    }
    print("\n");
    return 0;
}

int checkPrime(int n){
    int i,flag;
    for (i=2;i<n;i++){
        if (n%i==0){
            flag = 0;
        }
    }
    if (flag == 0){
        return 0;
    }
    else{
        return 1;
    }
}