#include <iostream>
using namespace std;

int n;
int board[20];
int solutionCount = 0;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

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

        if (isSafe(row, col)) {
            cout << "Placed at (" << row << "," << col << ")\n";
            board[row] = col;
            solve(row + 1);
            cout << "Backtracking from (" << row << "," << col << ")\n";
        } else {
            cout << "Not safe at (" << row << "," << col << ")\n";
        }
    }
}

int main() {
    cout << "Enter number of queens: ";
    cin >> n;

    solve(0);

    cout << "\nTotal Solutions: " << solutionCount << endl;

    return 0;
}