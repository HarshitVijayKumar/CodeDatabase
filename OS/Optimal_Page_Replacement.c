#include <stdio.h>

int findOptimal(int n,int order[]){
    int i,max=order[0];
    for(i=0;i<n;i++){
        if(order[i]>order[max]){
            max = i;
        }
    }
    return max;
}

int main(){
    int n,t,i,j,l;
    scanf("%d",&n);

    int page[n];
    for(i=0;i<n;i++){
        scanf("%d",&page[i]);
    }
    scanf("%d",&t);
    int frame_arr[t],fault_arr[t];
    for(i=0;i<t;i++){
        scanf("%d",&frame_arr[i]);
    }

    int k,fr,fault,found,od;
    for(i=0;i<t;i++){
        fr = frame_arr[i];
        int frame[fr],order[fr];
        for(j=0;j<fr;j++){
            frame[j] = -1;
            order[j] = -1;
        }
        k = 0;
        fault = 0;
        
        while(k<n){
            found=0;
            for(j=0;j<fr;j++){
                if(found==0){
                    if(frame[j]==-1){
                        frame[j] = page[k];
                        fault++;
                        found=1;
                    }
                    else if(frame[j] == page[k]){
                        found=1;
                    }
                }
            }
            if(found==1){
                k++;
                continue;
            }
            for(j=0;j<fr;j++){
                for(l=k+1;l<n;l++){
                    if(frame[j]==page[l]){
                        break;
                    }
                }
                order[j] = l;
            }
            od = findOptimal(fr,order);
            frame[od] = page[k];
            k++;
            fault++;
        }
        fault_arr[i] = fault;
    }

    printf("The fault array is : [");
    for(i=0;i<t;i++){
        printf("%d, ",fault_arr[i]);
    }
    printf("]\n");
    return 0;
}