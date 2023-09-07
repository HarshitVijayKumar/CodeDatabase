#include <stdio.h>

int main(){
    int n,i,j,flag;
    printf("Input the number of elements stored in the array : ");
    scanf("%d",&n);
    
    int a[n];
    printf("Input %d elements in the array\n",n);
    for (i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&a[i]);
    }
    printf("The unique elements found in the array are :\n");
    for (i=0;i<n;i++){
        flag = 0;
        for (j=0;j<n;j++){
            if (i!=j){
                if (a[i] == a[j]){
                    flag = 1;
                }
            }
        }
        if (flag == 0){
            printf("%d ",a[i]);
        }
    }
    printf("\n");
    return 0;
}