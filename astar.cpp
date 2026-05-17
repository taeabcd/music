#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct Node {
    vector<vector<int>> state;
    int g, h;
    string path;

    int f() const {
        return g + h;
    }
};

struct Compare {
    bool operator()(Node a, Node b) {
        return a.f() > b.f();
    }
};

// Heuristic Function
int heuristic(vector<vector<int>> state, vector<vector<int>> goal) {
    int count = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state[i][j] != 0 &&
                state[i][j] != goal[i][j]) {
                count++;
            }
        }
    }

    return count;
}

// Convert state to string
string stateToString(vector<vector<int>> state) {
    string s = "";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            s += to_string(state[i][j]);
        }
    }

    return s;
}

// Print puzzle state
void printState(vector<vector<int>> state) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (state[i][j] == 0)
                cout << "_ ";
            else
                cout << state[i][j] << " ";
        }

        cout << endl;
    }
}

// Check if puzzle is solvable
bool isSolvable(vector<vector<int>> puzzle) {

    vector<int> arr;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (puzzle[i][j] != 0)
                arr.push_back(puzzle[i][j]);
        }
    }

    int inversions = 0;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {

            if (arr[i] > arr[j])
                inversions++;
        }
    }

    return (inversions % 2 == 0);
}

void solvePuzzle(vector<vector<int>> start,
                 vector<vector<int>> goal) {

    // Check solvable condition
    if (!isSolvable(start)) {
        cout << "\nSolution does NOT exist!" << endl;
        return;
    }

    priority_queue<Node,
                   vector<Node>,
                   Compare> pq;

    map<string, bool> visited;

    Node root;
    root.state = start;
    root.g = 0;
    root.h = heuristic(start, goal);
    root.path = "";

    pq.push(root);

    int iteration = 1;

    while (!pq.empty()) {

        Node current = pq.top();
        pq.pop();

        string key = stateToString(current.state);

        if (visited[key])
            continue;

        visited[key] = true;

        cout << "\nIteration "
             << iteration++ << endl;

        cout << "Current State:" << endl;

        printState(current.state);

        cout << "g(n) = "
             << current.g << endl;

        cout << "h(n) = "
             << current.h << endl;

        cout << "f(n) = "
             << current.f() << endl;

        // Goal check
        if (current.state == goal) {

            cout << "\nGoal State Reached!"
                 << endl;

            cout << "Total Moves: "
                 << current.g << endl;

            cout << "Path: "
                 << current.path << endl;

            return;
        }

        int x, y;

        // Find blank tile
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                if (current.state[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        string move[] =
        {"Up", "Down", "Left", "Right"};

        for (int i = 0; i < 4; i++) {

            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 &&
                newX < 3 &&
                newY >= 0 &&
                newY < 3) {

                vector<vector<int>> newState =
                current.state;

                swap(newState[x][y],
                     newState[newX][newY]);

                string newKey =
                stateToString(newState);

                if (!visited[newKey]) {

                    Node child;

                    child.state = newState;
                    child.g = current.g + 1;
                    child.h =
                    heuristic(newState, goal);

                    child.path =
                    current.path + move[i] + " ";

                    pq.push(child);
                }
            }
        }
    }

    cout << "\nNo Solution Found!"
         << endl;
}

int main() {

    vector<vector<int>> start(3,
    vector<int>(3));

    vector<vector<int>> goal(3,
    vector<int>(3));

    cout << "Enter Initial State "
         << "(use 0 for blank):"
         << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            cin >> start[i][j];
        }
    }

    cout << "\nEnter Goal State:"
         << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            cin >> goal[i][j];
        }
    }

    cout << "\nA* Algorithm "
         << "for 8 Puzzle"
         << endl;

    solvePuzzle(start, goal);

    return 0;
}