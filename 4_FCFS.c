#include <stdio.h>

// Structure for Process
struct Process {
    int id, at, bt, ct, tat, wt;
};

// Function declarations
void input(struct Process p[], int n);
void sort(struct Process p[], int n);
void calc(struct Process p[], int n);
void show(struct Process p[], int n);

int main() {
    int n;

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];  // array of processes

    input(p, n);
    sort(p, n);
    calc(p, n);
    show(p, n);

    return 0;
}

// Input function
void input(struct Process p[], int n) {
    for(int i = 0; i < n; i++) {
        printf("\nEnter arrival time for process %d: ", i+1);
        scanf("%d", &p[i].at);

        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &p[i].bt);

        p[i].id = i + 1;
    }
}

// Sort by arrival time (Bubble Sort)
void sort(struct Process p[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(p[j].at > p[j+1].at) {
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

// FCFS calculation
void calc(struct Process p[], int n) {
    int time = 0;

    for(int i = 0; i < n; i++) {
        if(time < p[i].at) {
            time = p[i].at; // CPU idle
        }

        time += p[i].bt;
        p[i].ct = time;

        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

// Display result
void show(struct Process p[], int n) {
    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].id,
               p[i].at,
               p[i].bt,
               p[i].wt,
               p[i].tat);

        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
}
