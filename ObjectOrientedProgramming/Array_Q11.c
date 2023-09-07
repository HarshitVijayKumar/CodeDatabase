#include <stdio.h>

int main(){
    int n;

    printf("Input the size of the sqaure matrix(less than 5) : ");
    scanf("%d",&n);

    if ((n<5)&&(n>0)){
        int a[n][n],b[n][n],c[n][n];
        int i,j;

        printf("Input elements in the first matrix :\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("element - %d,%d : ",i,j);
                scanf("%d",&a[i][j]);
            }
        }
        printf("Input elements in the second matrix :\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("element - %d,%d : ",i,j);
                scanf("%d",&b[i][j]);
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                c[i][j]=a[i][j]-b[i][j];
            }
        }

        printf("The First matrix is :\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        printf("The Second matrix is :\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
        printf("The Subtraction of two matrix is :\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("Size of matrix is out of limits\n");
    }
    return 0;
}