#include<stdio.h>
#include<stdlib.h>
int main(){
    int np,i,AT[10],BT[10],CT[10],TAT[10],WT[10],CPUtime=0;
    int rem_time[10]={0},done=0,tq;
    float tot_wt=0,avg_wt=0;
    printf("Enter no. of processes:");
    scanf("%d",&np);
    printf("Enter time quantum:");
    scanf("%d",&tq);
    printf("Enter details following...\n");
    for(i=0;i<np;i++){
        printf("[P%d]",i+1);
        printf("Enter arrival time:");
        scanf("%d",&AT[i]);
        printf("Enter burst time:");
        scanf("%d",&BT[i]);
        rem_time[i]=BT[i];
              }
    while(done!=np){
        int executed=0;
        for(i=0;i<np;i++){
            if(AT[i]<=CPUtime && rem_time[i]>0){ //if process is usable & hasn't finished executing yet
                if(rem_time[i]<=tq){
                    CPUtime+=rem_time[i];
                    rem_time[i]=0; //marking as finished 
                    CT[i]=CPUtime;
                    done++;
                      }
                else{
                    CPUtime+=tq;
                    rem_time[i]-=tq;
                    }
                    executed=1;
                }
            }
    if(executed==0){
        CPUtime++;
    }
    }
    for(i=0;i<np;i++){
        TAT[i]=CT[i]-AT[i];
        WT[i]=TAT[i]-BT[i];
        tot_wt+=WT[i];
    }
    avg_wt=tot_wt/np;
    printf("PID\tAT\tBT\tCT\tWT\tTAT\n");
    for(i=0;i<np;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,AT[i],BT[i],CT[i],WT[i],TAT[i]);
            }
    printf("Avg WT:%.2f",avg_wt);
    return 0;
}
