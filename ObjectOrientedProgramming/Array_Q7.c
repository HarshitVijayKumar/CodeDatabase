#include <stdio.h>

int main(){
    int n,i,j,count,flag;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d",&n);
    
    int a[n],b[n],c[n];
    printf("Input %d elements in the array\n",n);
    for (i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++){
        count = 0;
        for (j=0;j<n;j++){
            if (a[i]==a[j]){
                count=count+1;
            }
        }
        b[i] = count;
    }
    for (i=0;i<n;i++){
        flag = 0;
        for (j=i+1;j<n;j++){
            if (i!=j){
                if (a[i]==a[j]){
                    flag = 1; 
                }
            }
        }
        c[i] = flag;
    }
    printf("The frequency of all elements of an array :\n");
    for (i=0;i<n;i++){
        if (c[i] == 0){
            printf("%d occurs %d times\n",a[i],b[i]);
        }
    }
    printf("\n");
    return 0;
}