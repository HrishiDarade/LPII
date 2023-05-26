#include <iostream>
#include <vector>

using namespace std;

bool checkSafety(const vector<vector<int>>& board, int row, int col) {
    int n = board.size();

    // Check for conflicting queen in the same row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check top left diagonal
    int r = row, c = col;
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 1) {
            return false;
        }
        r--;
        c--;
    }

    // Check bottom left diagonal
    r = row, c = col;
    while (r < n && c >= 0) {
        if (board[r][c] == 1) {
            return false;
        }
        r++;
        c--;
    }

    return true; // No conflicting queen present
}

bool solveNQueens(vector<vector<int>>& board, int col, int n) {
    if (col == n) {
        return true; // All queens have been placed successfully
    }

    for (int row = 0; row < n; row++) {
        if (checkSafety(board, row, col)) {
            board[row][col] = 1; // Place the queen

            if (solveNQueens(board, col + 1, n)) {
                return true; // Queen placement successful for remaining columns
            }

            board[row][col] = 0; // Backtrack and try next row
        }
    }

    return false; // Queen placement not possible for this configuration
}

void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            if (cell == 1) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

int main() {
    while (true) {
        int n;
        cout << "\nEnter the number of queens: ";
        cin >> n;

        if (n == -1) {
            cout << "\nThank You.....\n";
            break;
        }

        vector<vector<int>> board(n, vector<int>(n, 0));

        if (solveNQueens(board, 0, n)) {
            cout << "\n";
            printBoard(board);
        } else {
            cout << "\nSolution not possible\n";
        }

        cout << "\nEnter -1 to exit...\n";
    }

    return 0;
}
