#include <stdio.h>

int main() {
    int n,i,maxi,mini;

    printf("Enter the number of elemetns you want to enter :");
    scanf("%d",&n);

    int a[n];

    for (i=0;i<n;i++) {
        printf("Enter the %d number : ",i);
        scanf("%d",&a[i]);
    }

    maxi = a[0];
    mini = a[0];
    for (i=0;i<n;i++) {
        if(a[i]>maxi){
            maxi = a[i];
        }
        if(a[i]<mini){
            mini = a[i];
        }

    }

    printf("Maximum element : %d\n",maxi);
    printf("Minimum element : %d\n",mini);
    
    return 0;

}