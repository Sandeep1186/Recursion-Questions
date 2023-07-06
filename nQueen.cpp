#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& chessBoard, int row, int col) {
    // Check this row on the left
    for (int i = 0; i < col; i++) {
        if (chessBoard[row][i] == 1)
            return false;
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (chessBoard[i][j] == 1)
            return false;
    }

    // Check lower left diagonal
    for (int i = row, j = col; i < chessBoard.size() && j >= 0; i++, j--) {
        if (chessBoard[i][j] == 1)
            return false;
    }

    // Else it is safe to place a queen
    return true;
}

void addSolution(vector<vector<int>>& chessBoard, int n, vector<vector<int>>& ans) {
    vector<int> state;
    for (auto i : chessBoard) {
        for (auto j : i) {
            state.push_back(j);
        }
    }
    ans.push_back(state);
    return;
}

void nQueenHelper(vector<vector<int>>& chessBoard, int col, int n, vector<vector<int>>& ans) {
    // Base case
    if (col >= n) {
        addSolution(chessBoard, n, ans);
        return;
    }

    // Iterate over all the rows
    for (int row = 0; row < n; row++) {
        if (isSafe(chessBoard, row, col)) {
            // Mark this state with queen
            chessBoard[row][col] = 1;

            // Recursive call to the helper function for next column
            nQueenHelper(chessBoard, col + 1, n, ans);

            // Backtracking to the previous state
            chessBoard[row][col] = 0;
        }
    }
    return;
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> chessBoard(n, vector<int>(n, 0));

    nQueenHelper(chessBoard, 0, n, ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> solutions = solveNQueens(n);

    cout << "Number of solutions: " << solutions.size() << endl;

    for (int i = 0; i < solutions.size(); i++) {
        cout << "Solution " << i + 1 << ":" << endl;
        for (int j = 0; j < solutions[i].size(); j++) {
            for (int k = 0; k < solutions[i].size(); k++) {
                if (solutions[i][j] == k)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
    }

    
}
