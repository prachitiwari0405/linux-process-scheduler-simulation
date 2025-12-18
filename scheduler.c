#include <stdio.h>
#include "scheduler.h"

void fcfs(process_t p[], int n) {
    int time = 0;
    printf("\n--- FCFS Scheduling ---\n");

    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival_time)
            time = p[i].arrival_time;

        p[i].state = RUNNING;
        printf("Process %d running at time %d\n", p[i].pid, time);

        time += p[i].burst_time;
        p[i].completion_time = time;
        p[i].state = TERMINATED;
    }

    printf("\nPID\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", p[i].pid, p[i].completion_time);
    }
}

void round_robin(process_t p[], int n) {
    int time = 0;
    int completed = 0;
    printf("\n--- Round Robin Scheduling ---\n");

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0 && p[i].arrival_time <= time) {
                p[i].state = RUNNING;

                int exec_time = (p[i].remaining_time > TIME_QUANTUM)
                                ? TIME_QUANTUM
                                : p[i].remaining_time;

                printf("Process %d running from %d to %d\n",
                       p[i].pid, time, time + exec_time);

                time += exec_time;
                p[i].remaining_time -= exec_time;

                if (p[i].remaining_time == 0) {
                    p[i].completion_time = time;
                    p[i].state = TERMINATED;
                    completed++;
                }
            }
        }
    }

    printf("\nPID\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", p[i].pid, p[i].completion_time);
    }
}

int main() {
    process_t processes[] = {
        {1, 0, 5, 5, 0, READY},
        {2, 1, 3, 3, 0, READY},
        {3, 2, 6, 6, 0, READY}
    };

    int n = 3;

    fcfs(processes, n);

    // Reset remaining time for RR
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }

    round_robin(processes, n);

    return 0;
}
