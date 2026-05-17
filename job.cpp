#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job j[50];
    cout << "Enter job id, deadline, profit:\n";
    for (int i = 0; i < n; i++)
        cin >> j[i].id >> j[i].deadline >> j[i].profit;

    sort(j, j+n, cmp);

    int slot[50] = {0}, total = 0;

    cout << "\n--- Steps ---\n";

    for (int i = 0; i < n; i++) {

        cout << "\nConsidering Job " << j[i].id
             << " (Profit=" << j[i].profit
             << ", Deadline=" << j[i].deadline << ")\n";

        for (int k = j[i].deadline - 1; k >= 0; k--) {

            if (slot[k] == 0) {
                slot[k] = j[i].id;
                total += j[i].profit;

                cout << "Placed at slot " << k << endl;
                break;
            }
            else {
                cout << "Slot " << k << " already filled\n";
            }
        }
    }

    cout << "\nSelected jobs: ";
    for (int i = 0; i < n; i++)
        if (slot[i] != 0)
            cout << slot[i] << " ";

    cout << "\nTotal Profit: " << total;
}