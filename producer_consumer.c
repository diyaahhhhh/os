#include<stdio.h>
#define size 10
int buffer[size];
int count=0,in=0,out=0;
void producer(int item){
    if(count==size){
        printf("Buffer full!\n");
    }
    else{
        buffer[in]=item;
        in=(in+1)%size;
        count++;
        printf("Produced item %d\n",item);
    }
   }
void consumer(){
    if(count==0){
        printf("Buffer empty!\n");
    }
   else{
       int item=buffer[out];
       out=(out+1)%size;
       count--;
       printf("Consumed item %d\n",item);
   }
}
int main(){
    producer(1);
    producer(2);
    producer(3);
    consumer();
    consumer();
    consumer();
    consumer();
return 0;
}
