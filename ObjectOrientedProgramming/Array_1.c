#include <stdio.h>

int main() {
    int i,n;

    printf("Enter how many elements you want to enter :");
    scanf("%d",&n);

    int a[n];

    printf("Reading an array\n");
    for (i=0;i<n;i++){
        printf("Enter %d number :",i);
        scanf("%d",&a[i]);
    }

    printf("Printing an array\n");
    for (i=0;i<n;i++){
        printf("%d Number : %d\n",i,a[i]);
    }

    return 0;

}