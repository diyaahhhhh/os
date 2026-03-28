#include<stdio.h>
#include<stdlib.h>
int main(){
    int np,PID,i,AT[10],BT[10],CT[10],TAT[10],WT[10];
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
          }
    int temp,j;
    for(i=0;i<np;i++){
        for(j=i+1;j<=np;j++){
            if(AT[i]>AT[j]){
                temp=AT[i];
                AT[i]=AT[j]; //sorting AT
                AT[j]=temp;
                
                temp=BT[i];  //sorting BT
                BT[i]=BT[j];
                BT[j]=temp;
            }
          }
        }
    if()
