#include <stdio.h>

int main(){
    int n,i;
    printf("Input the number of elements to store in the array : ");
    scanf("%d",&n);

    int a[n];
    printf("Input %d number of elements in the array :\n",n);
    for (i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&a[i]);
    }
    printf("The values stored into the array are :\n");
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("The values stored into the array in reverse order are :\n");
    for (i=1;i<=n;i++){
        printf("%d ",a[n-i]);
    }
    printf("\n");
    return 0;
}