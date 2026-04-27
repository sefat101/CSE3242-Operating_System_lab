/*Question 4 — FCFS Scheduling
Write a program to implement First Come First Serve (FCFS) CPU scheduling algorithm and calculate:

Waiting Time

Turnaround Time

Average Waiting Time

Average Turnaround Time */

#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int id, at, bt, ct, tat, wt;
};

int main() {
    int n;
    cout << "\nEnter number of processes: ";
    cin >> n;

    Process p[n];

    // Input
    for(int i = 0; i < n; i++) {
        cout << "\nEnter arrival time for process " << i+1 << ": ";
        cin >> p[i].at;

        cout << "Enter burst time for process " << i+1 << ": ";
        cin >> p[i].bt;

        p[i].id = i + 1;
    }

    // Sort (built-in)
    sort(p, p + n, [](Process a, Process b) {
        return (a.at == b.at) ? a.id < b.id : a.at < b.at;
    });

    // Calculation
    int time = 0;
    for(int i = 0; i < n; i++) {
        if(time < p[i].at) time = p[i].at;

        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    // Output
    float total_wt = 0, total_tat = 0;

    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";

    for(int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].wt << "\t"
             << p[i].tat << "\n";

        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    cout << "\nAverage Waiting Time = " << total_wt / n;
    cout << "\nAverage Turnaround Time = " << total_tat / n << "\n";

    return 0;
}
