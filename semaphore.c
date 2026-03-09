#include <stdio.h>
#define SIZE 5   // buffer size

int buffer[SIZE];
int in = 0;      // index for producer
int out = 0;     // index for consumer
int count = 0;   // number of items in buffer

void produce(int item) {
    if(count == SIZE) {
        printf("Buffer full! Producer waits...\n");
    } else {
        buffer[in] = item;
        in = (in + 1) % SIZE;
        count++;
        printf("Producer produced item %d\n", item);
    }
}

void consume() {
    if(count == 0) {
        printf("Buffer empty! Consumer waits...\n");
    } else {
        int item = buffer[out];
        out = (out + 1) % SIZE;
        count--;
        printf("Consumer consumed item %d\n", item);
    }
}

int main() {
    // simulate sequence of produce and consume
    produce(1);
    produce(2);
    consume();
    produce(3);
    consume();
    consume();
    consume(); // this will show "Consumer waits" because buffer empty
    return 0;
}
