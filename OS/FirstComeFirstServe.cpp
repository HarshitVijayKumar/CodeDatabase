#include <iostream>
using namespace std;

int main(){
    int n,i;
    cout<<"Enter Number of Processes : ";
    cin>>n;
    int at[n],bt[n],ct[n],wt[n],tat[n],completed[n];
    for(i=0;i<n;i++){
        cout<<"Enter AT and BT for process "<<i<<" :";
        cin>>at[i]>>bt[i];
        completed[i] = 0;
    }
    int time=0,flag=0,found=-1;
    cout<<"Gantz Chart : "<<endl;
    while(flag==0){
        found=-1;
        for(i=0;i<n;i++){
            if ((at[i]<=time)&&(completed[i]==0)){
                found = i;
                break;
            }
        }
        if(found==-1){
            cout<<"Deadlock !"<<endl;
            break;
        }
        cout<<"| P("<<found<<") ";
        wt[found] = time-at[found];
        time = time+bt[found];
        ct[found] = time;
        completed[found] = 1;
        flag=1;
        for(i=0;i<n;i++){
            if(completed[i] == 0){
                flag=0;
            }
        }
    }
    cout<<"|"<<endl;

    for(i=0;i<n;i++){
        tat[i] = ct[i]-at[i];
    }

    double average_wt=0.0,average_tat=0.0;
    for(i=0;i<n;i++){
        average_wt = average_wt+wt[i];
        average_tat = average_tat+tat[i];
    }
    average_wt = average_wt/(double)n;
    average_tat = average_tat/(double)n;
    cout<<"Average waiting time is : "<<average_wt<<endl;
    cout<<"Average turn around time is : "<<average_tat<<endl;
    cout<<"|"<<endl;
    return 0;
}