/*Question 5 — SJF Non-Preemptive
Implement Shortest Job First (Non-Preemptive) scheduling algorithm.
Display:

Gantt Chart

Waiting Time

Turnaround Time*/



#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int id, at, bt, ct, tat, wt;
    bool done = false;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];

    // Input
    for(int i = 0; i < n; i++) {
        cout << "\nEnter AT and BT for P" << i+1 << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].id = i + 1;
    }

    // Sort by arrival time
    sort(p, p + n, [](Process a, Process b){
        return (a.at == b.at) ? a.id < b.id : a.at < b.at;
    });

    int time = 0, completed = 0;

    cout << "\nGantt Chart:\n|";

    while(completed < n) {
        int idx = -1;
        int min_bt = 1e9;

        // Find shortest job among arrived processes
        for(int i = 0; i < n; i++) {
            if(!p[i].done && p[i].at <= time && p[i].bt < min_bt) {
                min_bt = p[i].bt;
                idx = i;
            }
        }

        // If no process available → CPU idle
        if(idx == -1) {
            time++;
            continue;
        }

        // Execute process
        cout << " P" << p[idx].id << " |";
        time += p[idx].bt;

        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        p[idx].done = true;

        completed++;
    }

    // Output Table
    float total_wt = 0, total_tat = 0;

    cout << "\n\nProcess\tAT\tBT\tWT\tTAT\n";

    for(int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].wt << "\t"
             << p[i].tat << "\n";

        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    cout << "\nAverage WT = " << total_wt / n;
    cout << "\nAverage TAT = " << total_tat / n << "\n";

    return 0;
}
