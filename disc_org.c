#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, i, j, head, choice;
    int req[50], visited[50] = {0};
    int total_seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\n1. SSTF\n2. LOOK\n3. C-SCAN\nEnter choice: ");
    scanf("%d", &choice);

    // ---------------- SSTF ----------------
    if(choice == 1) {

        for(i = 0; i < n; i++) {
            int min = 10000, index = -1;

            for(j = 0; j < n; j++) {
                if(!visited[j]) {
                    int dist = abs(head - req[j]);
                    if(dist < min) {
                        min = dist;
                        index = j;
                    }
                }
            }

            visited[index] = 1;
            total_seek += min;
            head = req[index];
        }
    }

    // ---------------- LOOK ----------------
    else if(choice == 2) {

        // sort requests
        for(i = 0; i < n-1; i++)
            for(j = i+1; j < n; j++)
                if(req[i] > req[j]) {
                    int t = req[i];
                    req[i] = req[j];
                    req[j] = t;
                }

        // move right first
        for(i = 0; i < n; i++) {
            if(req[i] >= head) {
                total_seek += abs(head - req[i]);
                head = req[i];
            }
        }

        // then reverse
        for(i = n-1; i >= 0; i--) {
            if(req[i] < head) {
                total_seek += abs(head - req[i]);
                head = req[i];
            }
        }
    }

    // ---------------- C-SCAN ----------------
    else if(choice == 3) {

        int disk_size = 199;

        // sort requests
        for(i = 0; i < n-1; i++)
            for(j = i+1; j < n; j++)
                if(req[i] > req[j]) {
                    int t = req[i];
                    req[i] = req[j];
                    req[j] = t;
                }

        // move right
        for(i = 0; i < n; i++) {
            if(req[i] >= head) {
                total_seek += abs(head - req[i]);
                head = req[i];
            }
        }

        // go to disk end
        total_seek += abs(head - disk_size);

        // jump to start
        head = 0;

        // serve remaining
        for(i = 0; i < n; i++) {
            if(req[i] < head) {
                total_seek += abs(head - req[i]);
                head = req[i];
            }
        }
    }

    printf("\nTotal Seek Time = %d\n", total_seek);

    return 0;
}
