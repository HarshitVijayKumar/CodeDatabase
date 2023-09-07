#include <stdio.h>

int main() {
    int n,i;
    float average;

    printf("Enter number of elements :");
    scanf("%d",&n);

    int a[n];

    for (i=0;i<n;i++) {
        printf("Enter %d element : ",i);
        scanf("%d",&a[i]);
    }
    
    for (i=0;i<n;i++) {
        average = (average+a[i]);
    }
    average = average/n;
    printf("The average of the array is : %f",average);

    return 0;

}