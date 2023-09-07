#include <stdio.h>

int main(){
    int n1,n2,n3,n4,i,j,k,sum;

    printf("Input the rows and columns of first matrix : ");
    scanf("%d%d",&n1,&n2);
    printf("Input the rows and columns of second matrix : ");
    scanf("%d%d",&n3,&n4);

    int a[n1][n2],b[n3][n4],c[n1][n4];

    printf("Input elements in the first matrix :\n");
    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            printf("element - %d,%d : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Input elements in the second matrix :\n");
    for(i=0;i<n3;i++){
        for(j=0;j<n4;j++){
            printf("element - %d,%d : ",i,j);
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<n1;i++){
        for(j=0;j<n4;j++){
            sum = 0;
            for(k=0;k<n4;k++){
                sum = sum + a[i][k]*b[k][j]; 
            }
            c[i][j] = sum;
        }
    }

    printf("The First matrix is :\n");
    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("The Second matrix is :\n");
    for(i=0;i<n3;i++){
        for(j=0;j<n4;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    printf("The multiplication of two matrix is :\n");
    for(i=0;i<n1;i++){
        for(j=0;j<n4;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}