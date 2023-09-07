#include <stdio.h>

int main(){
    int n,i,j,flag;

    printf("Enter the number of elements to be stored in the array : ");
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
    printf("\n");
    printf("The missing number is : ");
    for(i=1;i<n+1;i++){
        flag = 0;
        for(j=0;j<n;j++){
            if (a[j]==i){
                flag = 1;
            }
        }
        if (flag==0){
            printf("%d ",i);
        }
    }
    return 0;
}