#include <stdio.h>

int main(){
  int n,i,j,q;
  scanf("%d",&n);
  int bt[n],at[n],rem_bt[n],ct[n],wt[n],tat[n],completed[n];
  for(i=0;i<n;i++){
    scanf("%d %d",&at[i],&bt[i]);
  }
  scanf("%d",&q);
  int curr_process,temp,flag=1,time=0;
  float sum_tat=0.00,sum_wt=0.00;

  for(i=0;i<n;i++){
    completed[i]=0;
    rem_bt[i] = bt[i];
  }

  printf("Gantt Chart : \n");
  j=0;
  while(flag==1){
    temp=0;
    while(temp==0){
      if((at[j]<=time)&&(completed[j]==0)){
        curr_process = j;
        temp = 1;
      }
      else{
        j=(j+1)%n;
      }
    }
    if(rem_bt[curr_process]<=q){
      time = time+rem_bt[curr_process];
      printf("| P%d (%d) ",curr_process,time);
      rem_bt[curr_process] = 0;
      ct[curr_process] = time;
      tat[curr_process] = ct[curr_process]-at[curr_process];
      wt[curr_process] = tat[curr_process]-bt[curr_process];
      sum_tat = sum_tat+tat[curr_process];
      sum_wt = sum_wt+wt[curr_process];
      completed[curr_process] = 1;
      j = (j+1)%n;
    }
    else{
      time = time+q;
      printf("| P%d (%d) ",curr_process,time);
      rem_bt[curr_process] = rem_bt[curr_process]-q;
      j = (j+1)%n;
    }
    flag = 0;
    for(i=0;i<n;i++){
      if(completed[i] == 0)
        flag=1;
    }
  }
  printf("|\n");
  printf("\n");
  printf(" Average Waiting and Turn Around Times are %.2f and %.2f milliseconds\n",sum_wt/n,sum_tat/n);
  return 0;
}
