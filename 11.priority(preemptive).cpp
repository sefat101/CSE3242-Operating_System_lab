#include <iostream>
using namespace std;

struct Process {
    int id, at, bt, pr, ct, tat, wt, rt;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];

    for(int i = 0; i < n; i++) {
        cout << "\nEnter AT, BT, Priority for P" << i+1 << ": ";
        cin >> p[i].at >> p[i].bt >> p[i].pr;
        p[i].id = i + 1;
        p[i].rt = p[i].bt; // remaining time
    }

    int time = 0, completed = 0;

    cout << "\nGantt Chart:\n|";

    while(completed < n) {
        int idx = -1, best_pr = 1e9;

        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].rt > 0 && p[i].pr < best_pr) {
                best_pr = p[i].pr;
                idx = i;
            }
        }

        if(idx == -1) {
            time++;
            continue;
        }

        cout << " P" << p[idx].id << " |";

        p[idx].rt--;   // run for 1 unit
        time++;

        if(p[idx].rt == 0) {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            completed++;
        }
    }

    cout << "\n\nProcess\tAT\tBT\tPR\tWT\tTAT\n";
    float twt=0, ttat=0;

    for(int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t" << p[i].at << "\t"
             << p[i].bt << "\t" << p[i].pr << "\t"
             << p[i].wt << "\t" << p[i].tat << "\n";

        twt += p[i].wt;
        ttat += p[i].tat;
    }

    cout << "\nAvg WT = " << twt/n;
    cout << "\nAvg TAT = " << ttat/n;
}
