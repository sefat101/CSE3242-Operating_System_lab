#include <iostream>
using namespace std;

struct Process {
    int id, at, bt, rt, ct, tat, wt;
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
        p[i].rt = p[i].bt; // remaining time
    }

    int time = 0, completed = 0;

    cout << "\nGantt Chart:\n|";

    while(completed < n) {
        int idx = -1;

        // Find process with shortest remaining time
        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].rt > 0 &&
              (idx == -1 || p[i].rt < p[idx].rt)) {
                idx = i;
            }
        }

        // If no process available
        if(idx == -1) {
            time++;
            continue;
        }

        cout << " P" << p[idx].id << " |";

        // Execute for 1 unit
        p[idx].rt--;
        time++;

        // If process completes
        if(p[idx].rt == 0) {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            completed++;
        }
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
