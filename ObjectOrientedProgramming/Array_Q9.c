/*Selection Sort*/
#include <stdio.h>

int main() {
    int n,i,j,min_index;

    printf("Input the size of array : ");
    scanf("%d",&n);

    int a[n];

    printf("Input %d elements in the array\n",n);
    for (i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++){
        min_index = i;
        for (j=i+1;j<n;j++){
            if (a[j]<a[min_index]){
                min_index = j;
            }
        }
        if (min_index != i){
            a[i] = a[i]+a[min_index];
            a[min_index] = a[i]-a[min_index];
            a[i] = a[i]-a[min_index];
        }
    }
    printf("Elements of the array in sorted ascending order:\n");
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}