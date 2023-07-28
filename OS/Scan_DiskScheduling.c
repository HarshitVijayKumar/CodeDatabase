#include <stdio.h>

int main(){
    int n,i,j,min,temp;
    scanf("%d",&n);
    int disk[n],head,seek;
    for(i=0;i<n;i++){
        scanf("%d",&disk[i]);
    }
    scanf("%d",&head);
    for(i=0;i<n;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(disk[j]<disk[min]){
                min = j;
            }
        }
        temp = disk[min];
        disk[min] = disk[i];
        disk[i] = temp;
    }
    while(head>0){
        head = head-1;
        seek = seek+1;
    }
    while(head<200){
        head = head+1;
        seek = seek+1;
    }
    seek = seek+199-disk[j];
    printf("Seek Time : %d\n",seek);
    printf("Average Seek Time : %f\n",(double)seek/(double)n);
}