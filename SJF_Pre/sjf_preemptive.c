#include <stdio.h>
#include <stdlib.h>

#define LEN 4

struct Process {
    int id, at, bt, rt, ct, wt, tat;
};

int main() {
    int completed = 0, time = 0;
    
    // Array of pointers to Process structs
    struct Process *p[LEN];

    // Initialize and allocate each process
    for (int i = 0; i < LEN; i++) {
        p[i] = (struct Process *)malloc(sizeof(struct Process));
        
        p[i]->id = i + 1;
        printf("Enter Arrival & Burst for P%d: ", i + 1);
        scanf("%d %d", &p[i]->at, &p[i]->bt);
        p[i]->rt = p[i]->bt; // Initialize remaining time
    }

    // Main Scheduling Loop
    while (completed < LEN) {
        int best = -1;

        // Find the process with shortest remaining time available at current 'time'
        for (int i = 0; i < LEN; i++) {
            if (p[i]->at <= time && p[i]->rt > 0) {
                if (best == -1 || p[i]->rt < p[best]->rt) {
                    best = i;
                }
            }
        }

        if (best != -1) {
            p[best]->rt--; // Execute for 1 time unit
            
            if (p[best]->rt == 0) { // Process finished
                completed++;
                p[best]->ct = time + 1;
                p[best]->tat = p[best]->ct - p[best]->at;
                p[best]->wt = p[best]->tat - p[best]->bt;
            }
        }
        time++; 
    }

    // Display Results
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < LEN; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i]->id, p[i]->at, p[i]->bt, p[i]->ct, p[i]->tat, p[i]->wt);
    }

    // Free individual allocated structs
    for (int i = 0; i < LEN; i++) {
        free(p[i]);
    }

    return 0;
}