#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i;
    scanf("%d",&n);
    int disk[n],seek,head;
    for(i=0;i<n;i++){
        scanf("%d",&disk[i]);
    }
    scanf("%d",&head);
    seek=0;
    for(i=0;i<n;i++){
        seek = seek+abs(head-disk[i]);
        head = disk[i];
    }
    printf("Seek Time : %d\n",seek);
    printf("Average Seek Time : %f\n",(double)seek/(double)n);
    return 0;
}