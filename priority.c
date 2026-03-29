#include<stdio.h>
#include<stdlib.h>
int main(){
    int np,i,AT[10],BT[10],CT[10],TAT[10],WT[10],CPUtime=0;
    int completed[10]={0},count=0,k,priority[10];
    float tot_wt=0,avg_wt=0;
    printf("Enter no. of processes:");
    scanf("%d",&np);
    printf("Enter details following...\n");
    for(i=0;i<np;i++){
        printf("[P%d]",i+1);
        printf("Enter arrival time:");
        scanf("%d",&AT[i]);
        printf("Enter burst time:");
        scanf("%d",&BT[i]);
        printf("Enter priority:");
        scanf("%d",&priority[i]);
              }
    int temp,j;
    for(i=0;i<np;i++){
        for(j=i+1;j<np;j++){
            if(AT[i]>AT[j]){
                temp=AT[i];
                AT[i]=AT[j]; //sorting AT
                AT[j]=temp;
                
                temp=BT[i];  //sorting BT
                BT[i]=BT[j];
                BT[j]=temp;
            } } }
    while(count<np){
        int min=999,index=-1;
        for(i=0;i<np;i++){
            if(AT[i]<=CPUtime && completed[i]==0){ //if process is usable & hasn't executed yet
                if(BT[i]<min){ //if this process has the smallest BT among all
                    min=BT[i];
                    index=i; //Currently this is the best process
                }
            }
        }
        if(index==-1){  //To handle idle time
            CPUtime++;
            continue;
        }
        CPUtime+=BT[index]; 
        CT[index]=CPUtime;
        TAT[index]=CT[index]-AT[index];
        WT[index]=TAT[index]-BT[index];
        tot_wt+=WT[index];
        completed[index]=1;
        count++;
    }
    avg_wt=tot_wt/np;
    printf("PID\tAT\tBT\tCT\tWT\tTAT\n");
    for(i=0;i<np;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",order[k],AT[i],BT[i],CT[i],WT[i],TAT[i]);
            }
    printf("Avg WT:%.2f",avg_wt);
    return 0;
}
