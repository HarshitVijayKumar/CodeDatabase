#include <stdio.h>

int main(){
    int n,i,even=0,odd=0,index1=0,index2=0;
    
    printf("Input the number of elements to be stored in the array :");
    scanf("%d",&n);
    
    int a[n],b[n],c[n];
    
    printf("Inputting %d elements in the array\n",n);
    for (i=0;i<n;i++){
        printf("element-%d : ",i);
        scanf("%d",&a[i]);
    }
    
    for (i=0;i<n;i++){
        if (a[i]%2==0){
            even = even+1;
            b[index1] = a[i];
            index1 = index1+1;
        }
        else {
            odd = odd+1;
            c[index2]= a[i];
            index2 = index2+1;
        }
    }
    printf("The Even elements are :\n");
    for (i=0;i<even;i++){
        printf("%d ",b[i]);
    }
    printf("\n");
    printf("The Odd elements are :\n");
    for (i=0;i<odd;i++){
        printf("%d ",c[i]);
    }
    return 0;
}