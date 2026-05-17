#include <iostream>
using namespace std;

int n;
int board[20];
bool colUsed[20];     // columns
bool diag1[40];       // row+col
bool diag2[40];       // row-col+n
int solutionCount = 0;

void printBoard() {
    cout << "\nSolution " << ++solutionCount << ":\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
}

void solve(int row) {

    if (row == n) {
        printBoard();
        return;
    }

    for (int col = 0; col < n; col++) {
        cout << "Trying (" << row << "," << col << ")...\n";
        if (!colUsed[col] && !diag1[row + col] && !diag2[row - col + n]) {

            cout << "Placed at (" << row << "," << col << ")\n";
            board[row] = col;
            colUsed[col] = true;
            diag1[row + col] = true;
            diag2[row - col + n] = true;

            solve(row + 1);
            cout << "Backtracking from (" << row << "," << col << ")\n";

            colUsed[col] = false;
            diag1[row + col] = false;
            diag2[row - col + n] = false;
        }
        else {
            cout << "Not safe at (" << row << "," << col << ")\n";
        }
    }
}

int main() {
    cout << "Enter number of queens: ";
    cin >> n;
    for (int i = 0; i < 20; i++) colUsed[i] = false;
    for (int i = 0; i < 40; i++) diag1[i] = diag2[i] = false;
    solve(0);
    cout << "\nTotal Solutions: " << solutionCount << endl;
    return 0;
}
