/*Q1. Write a C program to remove duplicate elements from an array.*/
#include <stdio.h>

int main() {
    int n,i,j,flag,index=0;

    printf("Enter the number of elements : ");
    scanf("%d",&n);

    int a[n],b[n];
    for (i=0;i<n;i++){
        printf("Element - %d : ",i);
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++){
        flag = 0;
        for (j=i+1;j<n;j++){
            if (a[i] == a[j]){
                flag = 1;
            }
        }
        if (flag == 0){
            b[index] = a[i];
            index = index+1;
        }
    }
    printf("The elements remaining are\n");
    for (i=0;i<index;i++){
        printf("%d ",b[i]);
    }
    return 0;
}