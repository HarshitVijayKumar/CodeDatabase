#include <stdio.h>

int main() {
    int n,i,j,max_index,sec_max;

    printf("Input the size of array : ");
    scanf("%d",&n);

    int a[n];
    
    printf("Input %d elements in the array\n",n);
    for (i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&a[i]);
    }
    max_index = 0;
    for (i=1;i<n;i++){
        if (a[i]>a[max_index]){
            max_index = i;
        }
        a[n-1] = a[n-1]+a[max_index];
        a[max_index] = a[n-1]-a[max_index];
        a[n-1]= a[n-1]-a[max_index];
    }
    sec_max = 0;
    for (i=0;i<n-1;i++){
        if (i != max_index){
            if (a[i]>a[sec_max]){
                sec_max = i;
            }
        }
    }
    printf("The second largest element in the array is : %d",a[sec_max]);
    printf("\n");
    return 0;
}