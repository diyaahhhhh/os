#include<stdio.h>
#include<stdlib.h>

int read_count=0;
int mutex=1;
int rw_mutex=1;

void wait(int *S){
    while(*S<=0);
    (*S)--;
}
void signal(int *S){
    (*S)++;
}
void reader(int ID){
    wait(&mutex); //locking
    read_count++;
    if(read_count==1){
        wait(&rw_mutex);
        }
    signal(&mutex);
    printf("Reader %d is reading...\n",ID);
    wait(&mutex);
    read_count--;
    if(read_count==0){
        signal(&rw_mutex);
    }
        signal(&mutex);
}
void writer(int ID){
    wait(&rw_mutex);
    printf("Writer %d is writing...\n",ID);
    signal(&rw_mutex);
}
int main(){
    reader(1);
    writer(1);
    reader(2);
    reader(3);
    writer(2);
return 0;
}
