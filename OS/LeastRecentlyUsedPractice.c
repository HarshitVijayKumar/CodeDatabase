#include <stdio.h>

int findLeastUsed(int n,int order[]){
    int i,max=order[0];
    for(i=1;i<n;i++){
        if(order[i]>order[max]){
            max = i;
        }
    }
    return max;
}

int main(){
    int n,t,i,j,k,flt,hit,fr,temp;
    scanf("%d",&n);
    int page[n];
    for(i=0;i<n;i++){
        scanf("%d",&page[i]);
    }
    scanf("%d",&t);
    int frame[t],fault[t];
    for(i=0;i<t;i++){
        scanf("%d",&frame[i]);
    }

    for(i=0;i<t;i++){
        fr = frame[i];
        int arr[fr];
        int order[fr];
        for(j=0;j<fr;j++){
            arr[j] = -1;
            order[j] = -1;
        }
        k=0;
        flt=0;
        while(k<n){
            hit=0;
            for(j=0;j<fr;j++){
                if(hit==0){
                    //Found
                    if(page[k]==arr[j]){
                        order[j] = 0;
                        hit=1;
                    }
                    //Not Found but Frame Not Full
                    else if(arr[j]==-1){
                        arr[j] = page[k];
                        order[j] = 0;
                        hit=1;
                        flt++;
                    }
                    else{
                        order[j]++;
                    }
                }
            }
            if(hit==0){
                //Not Found
                temp = findLeastUsed(fr,order);
                arr[temp] = page[k];
                order[temp] = 0;
                flt++;
            }
            k++;
        }
        fault[i] = flt;
    }
    printf("The number of faults are : [");
    for(i=0;i<t;i++){
        printf("%d, ",fault[i]);
    }
    printf("]\n");
}