/*Question 7 — Round Robin Scheduling
Implement Round Robin Scheduling using a user-defined time quantum.
Display:

Gantt Chart

Waiting Time

Turnaround Time*/

#include <iostream>
using namespace std;

struct Process {
    int id, at, bt, rt, ct, tat, wt;
};

int main() {
    int n, q;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];

    for(int i = 0; i < n; i++) {
        cout << "\nEnter AT and BT for P" << i+1 << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].id = i + 1;
        p[i].rt = p[i].bt; // remaining time
    }

    cout << "\nEnter Time Quantum: ";
    cin >> q;

    int time = 0, completed = 0;

    cout << "\nGantt Chart:\n|";

    while(completed < n) {
        bool executed = false;

        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].rt > 0) {

                executed = true;
                cout << " P" << p[i].id << " |";

                if(p[i].rt > q) {
                    time += q;
                    p[i].rt -= q;
                } else {
                    time += p[i].rt;
                    p[i].rt = 0;

                    p[i].ct = time;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;

                    completed++;
                }
            }
        }

        // CPU idle
        if(!executed) time++;
    }

    // Output
    float twt = 0, ttat = 0;

    cout << "\n\nProcess\tAT\tBT\tWT\tTAT\n";

    for(int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].wt << "\t"
             << p[i].tat << "\n";

        twt += p[i].wt;
        ttat += p[i].tat;
    }

    cout << "\nAverage WT = " << twt / n;
    cout << "\nAverage TAT = " << ttat / n;

    return 0;
}
