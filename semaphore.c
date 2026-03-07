#include <stdio.h>
#include <stdlib.h>

// Simulated semaphores
int rw_mutex = 1;   // resource lock
int mutex = 1;      // protects read_count
int read_try = 1;   // writer priority
int read_count = 0; // number of readers

// wait and signal functions
void wait(int *s) {
    while(*s <= 0); // busy wait
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

// Reader function
void reader(int id) {
    wait(&read_try);     // check if writers want priority
    wait(&mutex);
    read_count++;
    if(read_count == 1) wait(&rw_mutex); // first reader locks resource
    signal(&mutex);
    signal(&read_try);

    // critical section
    printf("Reader %d is reading...\n", id);

    wait(&mutex);
    read_count--;
    if(read_count == 0) signal(&rw_mutex); // last reader unlocks resource
    signal(&mutex);
}

// Writer function
void writer(int id) {
    wait(&read_try);   // block new readers
    wait(&rw_mutex);   // exclusive access

    // critical section
    printf("Writer %d is writing...\n", id);

    signal(&rw_mutex);
    signal(&read_try);
}

int main() {
    // simulate sequence of readers and writers
    reader(1);
    writer(1);
    reader(2);
    reader(3);
    writer(2);
    reader(4);

    return 0;
}
