#include <stdio.h>

int main() {
    int n,i,j,count,flag;

    printf("Enter the number ofelements to be stored in the array : ");
    scanf("%d",&n);

    int a[n];
    printf("Inputting %d elements in the array\n",n);
    for(i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&a[i]);
    }
    printf("The given array is : ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\nThe element occuring odd number of times is : ");
    for(i=0;i<n;i++){
        count = 0;
        for(j=0;j<n;j++){
            if (a[i]==a[j]){
                count = count+1;
            }
        }
        flag = 0;
        for(j=0;j<i;j++){
            if (a[i]==a[j]){
                flag = 1;
            }
        }
        if ((count%2!=0)&&(flag == 0)){
            printf("%d ",a[i]);
        }
    }
    return 0;
}