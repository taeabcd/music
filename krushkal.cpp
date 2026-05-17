#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure for edge
struct Edge {
    int u, v, weight;
};

// Compare edges by weight
bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set Union
class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {

        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {

        parent[find(x)] = find(y);
    }

    void printParents() {

        cout << "Parent Array: ";

        for(int i = 0; i < parent.size(); i++)
            cout << parent[i] << " ";

        cout << endl;
    }
};

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < E; i++) {

        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    // Sort edges
    sort(edges.begin(), edges.end(), cmp);

    cout << "\nEdges sorted by weight:\n";

    for(auto e : edges) {

        cout << e.u << " - "
             << e.v << " : "
             << e.weight << endl;
    }

    DSU dsu(V);

    int totalCost = 0;

    cout << "\n--- Iterations ---\n";

    int step = 1;

    for(auto e : edges) {

        int u = e.u;
        int v = e.v;
        int w = e.weight;

        cout << "\nIteration "
             << step++ << endl;

        cout << "Checking edge: "
             << u << " - "
             << v << " (Weight "
             << w << ")" << endl;

        cout << "Find(" << u << ") = "
             << dsu.find(u) << endl;

        cout << "Find(" << v << ") = "
             << dsu.find(v) << endl;

        // Cycle check
        if(dsu.find(u) != dsu.find(v)) {

            cout << "No cycle detected\n";

            cout << "Include edge: "
                 << u << " - "
                 << v << endl;

            totalCost += w;

            dsu.unite(u, v);

            dsu.printParents();

            cout << "Current MST Cost = "
                 << totalCost << endl;
        }
        else {

            cout << "Cycle detected\n";

            cout << "Discard edge: "
                 << u << " - "
                 << v << endl;
        }
    }

    cout << "\nTotal cost of MST: "
         << totalCost << endl;

    return 0;
}