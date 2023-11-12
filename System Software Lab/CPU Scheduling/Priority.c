#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pno, pri, btime, wtime;
} sp;

int main() {
    int i, j, n;
    int tbm = 0, totwtime = 0, totttime = 0;
    sp *p, t;

    printf("\nPriority Scheduling.\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    p = (sp *)malloc(n * sizeof(sp));

    printf("Enter the burst time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d%d", &p[i].btime, &p[i].pri);
        p[i].pno = i + 1;
        p[i].wtime = 0;
    }

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (p[i].pri > p[j].pri) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        totwtime += p[i].wtime = tbm;
        tbm += p[i].btime;
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pno, p[i].btime, p[i].wtime, p[i].wtime + p[i].btime);
    }

    totttime = tbm + totwtime;

    printf("\nTotal Waiting Time: %d", totwtime);
    printf("\nAverage Waiting Time: %f", (float)totwtime / n);
    printf("\nTotal Turnaround Time: %d", totttime);
    printf("\nAverage Turnaround Time: %f\n", (float)totttime / n);

    return 0;
}
