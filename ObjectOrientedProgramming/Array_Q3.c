#include <stdio.h>

int main(){
    int n,i,sum;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d",&n);

    int a[n];
    printf("Input %d elements in the array :\n",n);
    for (i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&a[i]);
    }
    sum = 0;
    for (i=0;i<n;i++){
        sum = (sum + a[i]);
    }
    printf("Sum of all elements stored in the array is : %d\n",sum);
    return 0;
}