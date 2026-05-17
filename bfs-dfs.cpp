#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100];
bool visited[100];
vector<int> dfsPath;
vector<int> bfsPath;

void DFS(int node) {
    cout << "Visit: " << node << endl;
    visited[node] = true;
    dfsPath.push_back(node);

    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];

        if (!visited[next]) {
            cout << "Move from " << node << " -> " << next << endl;
            DFS(next);
            cout << "Backtrack to " << node << endl;
        }
    }
}

void BFS(int start) {
    queue<int> q;
    bool vis[100] = {false};
    q.push(start);
    vis[start] = true;
    cout << "Push: " << start << endl;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Visit: " << node << endl;
        bfsPath.push_back(node);
        for (int i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i];
            if (!vis[next]) {
                q.push(next);
                vis[next] = true;
                cout << "Push: " << next << " (from " << node << ")" << endl;
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Vertices: ";
    cin >> V;
    cout << "Edges: ";
    cin >> E;
    cout << "Enter edges:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start;
    cout << "Start: ";
    cin >> start;
    cout << "\n--- DFS Steps ---\n";
    DFS(start);
    cout << "\nDFS Final Path: ";
    for (int i = 0; i < dfsPath.size(); i++) {
        cout << dfsPath[i] << " ";
    }
    cout << "\n\n--- BFS Steps ---\n";
    BFS(start);
    cout << "\nBFS Final Path: ";
    for (int i = 0; i < bfsPath.size(); i++) {
        cout << bfsPath[i] << " ";
    }

    return 0;
}
