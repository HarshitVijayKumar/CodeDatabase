#include <stdio.h>

int main() {
    int n,i;
    printf("Enter the number of elements :\n");
    scanf("%d",&n);

    int a[n];
    for (i=0;i<n;i++){
        printf("element - %d :",i);
        scanf("%d",&a[i]);
    }
    printf("Elements in array are: ");
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}