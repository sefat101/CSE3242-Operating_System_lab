/*Question 9 — Banker’s Algorithm
Write a program to implement the Banker’s Algorithm for deadlock avoidance.
The program should:

take Allocation, Maximum, and Available matrices as input

determine whether the system is in a safe state

display the safe sequence*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, r;
    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> r;

    vector<vector<int>> alloc(n, vector<int>(r));
    vector<vector<int>> max(n, vector<int>(r));
    vector<vector<int>> need(n, vector<int>(r));
    vector<int> avail(r);

    // Input Allocation
    cout << "\nEnter Allocation Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < r; j++)
            cin >> alloc[i][j];

    // Input Max
    cout << "\nEnter Max Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < r; j++)
            cin >> max[i][j];

    // Input Available
    cout << "\nEnter Available Resources:\n";
    for(int j = 0; j < r; j++)
        cin >> avail[j];

    // Calculate Need = Max - Allocation
    for(int i = 0; i < n; i++)
        for(int j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    vector<int> finish(n, 0), safeSeq;
    int completed = 0;

    // Banker's Algorithm
    while(completed < n) {
        bool found = false;

        for(int i = 0; i < n; i++) {
            if(!finish[i]) {
                bool canRun = true;

                for(int j = 0; j < r; j++) {
                    if(need[i][j] > avail[j]) {
                        canRun = false;
                        break;
                    }
                }

                // If process can execute
                if(canRun) {
                    for(int j = 0; j < r; j++)
                        avail[j] += alloc[i][j];

                    safeSeq.push_back(i);
                    finish[i] = 1;
                    completed++;
                    found = true;
                }
            }
        }

        // If no process can run → unsafe
        if(!found) break;
    }

    // Output result
    if(completed == n) {
        cout << "\nSystem is in SAFE state\n";
        cout << "Safe Sequence: ";
        for(int i = 0; i < n; i++) {
            cout << "P" << safeSeq[i];
            if(i != n-1) cout << " -> ";
        }
    } else {
        cout << "\nSystem is NOT in safe state (Deadlock possible)\n";
    }

    return 0;
}
