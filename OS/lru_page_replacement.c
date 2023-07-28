#include <stdio.h>

int find_least_recent(int order[],int n){
    int i,least=0;
    for(int i=1;i<n;i++){
        if(order[least]<order[i]){
            least = i;
        }
    }
    return least;
}

int main(){
    int t,i;
    scanf("%d",&t);
    int page[t],faults[t];
    for(i=0;i<t;i++){
        scanf("%d",&page[i]);
    }
    int n;
    scanf("%d",&n);
    int frame[n];
    for(i=0;i<n;i++){
        scanf("%d",&frame[i]);
    }

    int fr,j,k,found,least_recent,hit;
    for(i=0;i<n;i++){
        fr = frame[i];
        int array[fr];
        int order[fr];
        for(k=0;k<fr;k++){
            array[k] = -2147483647-1;
            order[k] = -1;
        }
        j=0;
        hit = 0;
        while(j<t){
            found = 0;
            for(k=0;k<fr;k++){
                if(found==0){
                    //Page is found in the frame array
                    if((array[k] == page[j])&&(found==0)){
                        order[k] = 0;
                        found = 1;
                        hit++;
                    }
                    //Page is not found but the frame array is not full
                    else if((array[k] == -2147483647-1)&&(found==0)){
                        array[k] = page[j];
                        order[k] = 0;
                        found = 1;
                        break;
                    }
                    //Increase the time for which the page was last used
                    else{
                        order[k]++;
                    }
                }
                else{
                    if((k<fr)&&(array[k]!=-2147483647-1)){
                        order[k]++;
                    }
                }
            }
            //If page is not found
            if(found==0){
                least_recent = find_least_recent(order,fr);
                array[least_recent] = page[j];
                order[least_recent] = 0;
            }
            j++;
        }
        faults[i] = t-hit;
    }
    printf("The number of page faults: [");
    for(int i=0;i<n-1;i++){
        printf("%d, ",faults[i]);
    }
    printf("%d]\n",faults[n-1]);
    return 0;
}