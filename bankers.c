#include <stdio.h>

int main() {
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m];

    printf("Enter allocation matrix:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter max matrix:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter available resources:\n");
    for(int j=0; j<m; j++)
        scanf("%d", &avail[j]);

    // Calculate need matrix
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int finish[n];
    for(int i=0; i<n; i++) finish[i] = 0;

    int safeSeq[n], count = 0;
    int work[m];
    for(int j=0; j<m; j++) work[j] = avail[j];

    while(count < n) {
        int found = 0;
        for(int i=0; i<n; i++) {
            if(finish[i] == 0) {
                int flag = 1;
                for(int j=0; j<m; j++) {
                    if(need[i][j] > work[j]) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    for(int j=0; j<m; j++)
                        work[j] += alloc[i][j];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0) {
            printf("System is NOT in a safe state.\n");
            return 0;
        }
    }

    printf("System is in a safe state.\nSafe sequence is: ");
    for(int i=0; i<n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}
