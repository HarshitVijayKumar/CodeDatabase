#include <stdio.h>

int main () {
    int n,i;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d",&n);

    int a[n],b[n];
    printf("Input %d elements in the array :\n",n);
    for (i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++){
        b[i] = a[i];
    }
    printf("The elements stored in the first array are :\n");
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("The elements copied in the second array are :\n");
    for (i=0;i<n;i++){
        printf("%d ",b[i]);
    }
    printf("\n");
    return 0;
}