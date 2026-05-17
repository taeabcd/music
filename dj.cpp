#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[10][10];
    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    int dist[10], visited[10] = {0};

    int start;
    cout << "Enter start node: ";
    cin >> start;

    for (int i = 0; i < n; i++)
        dist[i] = cost[start][i];

    visited[start] = 1;

    cout << "\n--- Steps ---\n";

    for (int i = 0; i < n-1; i++) {
        int min = 999, u;

        // Find minimum distance node
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        cout << "\nSelected Node: " << u << " (Distance=" << min << ")\n";

        visited[u] = 1;

        // Update distances
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[u] + cost[u][v] < dist[v]) {
                cout << "Updating distance of " << v
                     << " from " << dist[v]
                     << " to " << dist[u] + cost[u][v] << endl;

                dist[v] = dist[u] + cost[u][v];
            }
        }

        // Print current distances
        cout << "Current distances: ";
        for (int k = 0; k < n; k++)
            cout << dist[k] << " ";
        cout << endl;
    }

    cout << "\nShortest distances:\n";
    for (int i = 0; i < n; i++)
        cout << i << " -> " << dist[i] << endl;
}

