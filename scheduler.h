#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

typedef enum {
    READY,
    RUNNING,
    TERMINATED
} state_t;

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    state_t state;
} process_t;

void fcfs(process_t processes[], int n);
void round_robin(process_t processes[], int n);

#endif
