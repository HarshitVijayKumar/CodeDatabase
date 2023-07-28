#include <stdio.h>

int main(){
    int n,t;
    scanf("%d",&n);
    int at[n],bt[n],ct[n],wt[n],tat[n],rt[n],completed[n];
    int i,j,flag,time;
    for(i=0;i<n;i++){
        scanf("%d %d",&at[i],&bt[i]);
        rt[i] = bt[i];
        wt[i] = -1;
        completed[i] = 0;
    }
    printf("Enter the Time Quantum : ");
    scanf("%d",&t);

    printf("Gantz Charts : \n");
    flag=0;
    time=0;
    i=0;
    while(flag==0){
        if((at[i]<=time)&&(completed[i]==0)){
            printf("| P(%d) ",i);
            if(rt[i]<=t){
                time = time+rt[i];
                rt[i] = 0;
                ct[i] = time;
                completed[i] = 1;
                tat[i] = ct[i]-at[i];
                wt[i] = tat[i]-bt[i];
            }
            else{
                time = time+t;
                rt[i] = rt[i]-t;
            }
        }
        flag=1;
        for(j=0;j<n;j++){
            if(completed[j]==0){
                flag=0;
            }
        }
        i = (i+1)%n;
    }
    printf("|\n");
    double avg_wt=0.0,avg_tat=0.0;
    for(i=0;i<n;i++){
        avg_wt = avg_wt+wt[i];
        avg_tat = avg_tat+tat[i];
    }
    avg_wt = avg_wt/(double)n;
    avg_tat = avg_tat/(double)n;
    printf("The average waiting time is : %f\n",avg_wt);
    printf("The average turn around time is : %f\n",avg_tat);
    return 0;
}