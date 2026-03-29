#include<stdio.h>
#include<stdlib.h>
int main(){
    int np,i,AT[10],BT[10],CT[10],TAT[10],WT[10],CPUtime=0;
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
    for(i=0;i<np;i++){
    if(CPUtime<AT[i]){
        CPUtime=AT[i];
    }
        CPUtime+=BT[i];
        CT[i]=CPUtime;
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
