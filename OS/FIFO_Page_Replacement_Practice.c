#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int page[n];
    int i,j,k,l;
    for(i=0;i<n;i++){
        scanf("%d",&page[i]);
    }
    int t;
    scanf("%d",&t);
    int frame_arr[t],fault_arr[t];
    for(i=0;i<t;i++){
        scanf("%d",&frame_arr[i]);
    }

    int faults,frame,hit;
    for(i=0;i<t;i++){
        frame = frame_arr[i];
        faults=0;
        l=0;
        int arr[frame];
        for(j=0;j<frame;j++){
            arr[j] = -1;
        }
        k=0;
        while(k<n){
            hit=0;
            //The page is found
            for(j=0;j<frame;j++){
                if(arr[j]==page[k]){
                    hit=1;
                    break;
                }
            }
            if(hit==1){
                k++;
                continue;
            }
            //Page is not found and the array is not full
            faults++;
            hit=0;
            for(j=0;j<frame;j++){
                if(arr[j]==-1){
                    arr[j] = page[k];
                    hit=1;
                    break;
                }
            }
            if(hit==1){
                k++;
                continue;
            }
            //Page is not found and we remove the element
            arr[l] = page[k];
            l = (l+1)%frame;
            k++;
        }
        fault_arr[i] = faults;
    }
    printf("The page faults are : [ ");
    for(i=0;i<t;i++){
        printf("%d, ",fault_arr[i]);
    }
    printf("]\n");
    return 0;
}