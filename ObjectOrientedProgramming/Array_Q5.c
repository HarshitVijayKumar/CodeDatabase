#include <stdio.h>

int main(){
    int n,i,j,duplicate;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d",&n);
    
    int a[n];
    printf("Input %d elements in the array : \n",n);
    for (i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&a[i]);
    }
    duplicate = 0;
    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if (a[j]==a[i]){
                duplicate = duplicate+1;
            }
        }
    }
    printf("Total number of duplicate elements found in the array is : %d\n",duplicate);
    return 0;
}