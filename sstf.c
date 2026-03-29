#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, head,i,j,diff,min,done[10]={0},ST=0;
    printf("Enter no. of requests:");
    scanf("%d",&n);
    int req[n];
    printf("Enter request:");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter head:");
    scanf("%d",&head);
    printf("%d->",head);
    for(i=0;i<n;i++){
        min=999;
        int index=-1; //no request has been served yet
        for(j=0;j<n;j++){
            if(!done[j]){ //if not serviced
                diff=abs(head-req[j]);
                if(diff<min){
                    min=diff;
                    index=j; //j-moving position to closest request
                }
            }
        }
        ST+=min;
        head=req[index];
        done[index]=1;
       printf("->%d",head);
    }
    return 0;
}
