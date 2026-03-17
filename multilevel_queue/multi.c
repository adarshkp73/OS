#include <stdio.h>

typedef struct {
    int id, at, bt, rt, ct, tat, wt, q;
} Process;

void calculate_metrics(Process p[], int n) {
    float total_tat = 0, total_wt = 0;
    printf("\nID\tQ\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        total_tat += p[i].tat;
        total_wt += p[i].wt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].q, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAvg TAT: %.2f | Avg WT: %.2f\n", total_tat / n, total_wt / n);
}

int main() {
    int n, tq, time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum for Q1: ");
    scanf("%d", &tq);

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("P%d [AT, BT, Q(1=Sys, 2=User)]: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].q);
        p[i].rt = p[i].bt;
        p[i].ct = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j+1].at) {
                Process temp = p[j]; p[j] = p[j+1]; p[j+1] = temp;
            }
        }
    }

    while (completed < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (p[i].q == 1 && p[i].rt > 0 && p[i].at <= time) {
                found = 1;
                int execute = (p[i].rt > tq) ? tq : p[i].rt;
                time += execute;
                p[i].rt -= execute;
                if (p[i].rt == 0) {
                    p[i].ct = time;
                    completed++;
                }
            }
        }

        if (!found) {
            for (int i = 0; i < n; i++) {
                if (p[i].q == 2 && p[i].rt > 0 && p[i].at <= time) {
                    found = 1;
                    time += p[i].rt;
                    p[i].rt = 0;
                    p[i].ct = time;
                    completed++;
                    break; 
                }
            }
        }

        if (!found) time++;
    }

    calculate_metrics(p, n);
    return 0;
}