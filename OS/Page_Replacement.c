#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    int a[t];
    for(int i=0;i<t;i++){
        scanf("%d",&a[i]);
    }
    int n;
    scanf("%d",&n);
    int b[n];
    int fault_arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    int pointer,faults,frame_length;
    int k=0,flag=0;
    for(int j=0;j<n;j++){
        frame_length = b[j];
        faults = frame_length;
        pointer = 0;
        k=0;
        int frame_arr[frame_length];
        for(int i=0;i<frame_length;i++){
            frame_arr[i] = a[k];
            k++;
        }
        while(k<t){
            flag=0;
            for(int i=0;i<frame_length;i++){
                if(frame_arr[i]==a[k]){
                    flag=1;
                }
            }
            if(flag!=1){
                frame_arr[pointer] = a[k];
                faults++;
                pointer = (pointer+1)%frame_length;
            }
            k++;
        }
        fault_arr[j] = faults;
    }
    printf("The number of page faults: [");
    for(int i=0;i<n-1;i++){
        printf("%d, ",fault_arr[i]);
    }
    printf("%d]\n",fault_arr[n-1]);
    return 0;
}