#include <iostream>
using namespace std;

int main() {

    int V, E;

    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    int u[50], v[50], w[50];

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < E; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    int start;

    cout << "Enter starting node: ";
    cin >> start;

    int visited[50] = {0};

    visited[start] = 1;

    int edges = 0, mincost = 0;

    cout << "\n--- Prim's Iterations ---\n";

    while(edges < V-1) {

        int min = 999;
        int a = -1;
        int b = -1;

        cout << "\nIteration " << edges + 1 << endl;

        cout << "Visited vertices: ";

        for(int i = 0; i < V; i++) {
            if(visited[i])
                cout << i << " ";
        }

        cout << endl;

        cout << "Possible edges:\n";

        for(int i = 0; i < E; i++) {

            if((visited[u[i]] && !visited[v[i]]) ||
               (visited[v[i]] && !visited[u[i]])) {

                cout << u[i] << " - " << v[i]
                     << " Cost = " << w[i] << endl;

                if(w[i] < min) {

                    min = w[i];
                    a = u[i];
                    b = v[i];
                }
            }
        }

        if(a != -1 && b != -1) {

            cout << "Selected Edge: "
                 << a << " - " << b
                 << " Cost = " << min << endl;

            visited[a] = visited[b] = 1;

            mincost += min;

            edges++;

            cout << "Current Minimum Cost = "
                 << mincost << endl;
        }
        else {

            cout << "Graph is not connected!\n";
            return 0;
        }
    }

    cout << "\nTotal Minimum Cost = "
         << mincost << endl;

    return 0;
}