#include<stdio.h>

int main(){
int i,j,np, BT[10],WT[10],TAT[10];

printf("Enter the no. of processes:");
scanf("%d",&np);
int process[np];
for(i=0;i<np;i++){
    printf("Enter burst time of P%d:",i+1);
    scanf("%d",&BT[i]);
}
//sorting
int temp;
for(i=0;i<np;i++){
    for(j=i+1;j<=np;j++){
        if(BT[i]>BT[j]){  //if 1st element is bigger than 2nd element
            temp=BT[i];
            BT[i]=BT[j];
            BT[j]=temp;
        }
    }
}

WT[0]=0;
for(i=0;i<np;i++){
    WT[i]=WT[i-1]+BT[i-1];
}

for(i=0;i<np;i++){
    TAT[i]=WT[i]+BT[i];
}

printf("Process\tBT\tWT\tTAT\n");
for(i=0;i<np;i++){
    printf("P%d\t%d\t%d\t%d\n",i+1,BT[i],WT[i],TAT[i]);
}

return 0;
}
