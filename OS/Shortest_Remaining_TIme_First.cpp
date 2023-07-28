#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of processes : ";
    cin>>n;

    int at[n],bt[n],ct[n],wt[n],tat[n],rt[n],completed[n];
    int i,time,flag,found,min;
    for(i=0;i<n;i++){
        cout<<"Enter the AT and BT for process "<<i<<" : ";
        cin>>at[i]>>bt[i];
        completed[i] = 0;
        rt[i] = bt[i];
        wt[i] = -1;
    }

    time = 0;
    flag = 0;

    cout<<"Gantz Chart : "<<endl;
    while(flag==0){
        found=-1;
        min = 345637;
        for(i=0;i<n;i++){
            if((at[i]<=time)&&(completed[i]==0)){
                if(rt[i]<min){
                    min= rt[i];
                    found = i;
                }
            }
        }
        if(found==-1){
            time++;
            continue;
        }
        cout<<"| P("<<found<<") ";
        if(wt[found]==-1){
            wt[found] = time-at[found];
        }
        rt[found] = rt[found]-1;
        time++;
        if(rt[found]==0){
            completed[found] = 1;
            ct[found] = time;
        }
        flag=1;
        for(i=0;i<n;i++){
            if(completed[i]==0){
                flag=0;
            }
        }
    }
    cout<<"|"<<endl;
    double avg_wt=0.0,avg_tat=0.0;
    for(i=0;i<n;i++){
        tat[i] = ct[i]-at[i];
    }
    for(i=0;i<n;i++){
        avg_wt = avg_wt+wt[i];
        avg_tat = avg_tat+tat[i];
    }
    avg_wt = avg_wt/(double)n;
    avg_tat = avg_tat/(double)n;
    cout<<"The average waiting time is : "<<avg_wt<<endl;
    cout<<"The average turn around time is : "<<avg_tat<<endl;
    return 0;
}