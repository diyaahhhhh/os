#include <stdio.h>
#include <stdlib.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter pages (0-9): ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // ---------- FIFO ----------
    int fifo_faults = 0, index = 0;
    for(i = 0; i < f; i++) frames[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++)
            if(frames[j] == pages[i])
                found = 1;

        if(!found) {
            frames[index] = pages[i];
            index = (index + 1) % f;
            fifo_faults++;
        }
    }

    // ---------- LRU ----------
    int lru_faults = 0, time[10], count = 0;
    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                count++;
                time[j] = count;
                found = 1;
            }
        }

        if(!found) {
            int min = time[0], pos = 0;

            for(k = 1; k < f; k++) {
                if(time[k] < min) {
                    min = time[k];
                    pos = k;
                }
            }

            frames[pos] = pages[i];
            count++;
            time[pos] = count;
            lru_faults++;
        }
    }

    // ---------- Optimal ----------
    int opt_faults = 0;
    for(i = 0; i < f; i++) frames[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++)
            if(frames[j] == pages[i])
                found = 1;

        if(!found) {
            int pos = -1, farthest = i;

            for(j = 0; j < f; j++) {
                int next = -1;

                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {
                        next = k;
                        break;
                    }
                }

                if(next == -1) {
                    pos = j;
                    break;
                }

                if(next > farthest) {
                    farthest = next;
                    pos = j;
                }
            }

            if(pos == -1) pos = 0;

            frames[pos] = pages[i];
            opt_faults++;
        }
    }

    // ---------- Output ----------
    printf("\nPage Faults:\n");
    printf("FIFO = %d\n", fifo_faults);
    printf("LRU = %d\n", lru_faults);
    printf("Optimal = %d\n", opt_faults);

    return 0;
}
