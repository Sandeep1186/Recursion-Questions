#include <iostream>
#include <vector>
using namespace std;

void insertCurrentState(vector<vector<int>> &currentSolution, vector<vector<int>> &result, int size) {
    vector<int> currentState;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            currentState.push_back(currentSolution[i][j]);
        }
    }
    result.push_back(currentState);
}

void solveMaze(vector<vector<int>> &maze, vector<vector<int>> &currentSolution, vector<vector<int>> &result, int x, int y, int size) {
    if (x == size - 1 && y == size - 1) {
        currentSolution[x][y] = 1;
        insertCurrentState(currentSolution, result, size);
        return;
    }

    if (x >= size || x < 0 || y >= size || y < 0) {
        return;
    }

    if (maze[x][y] == 0 || currentSolution[x][y] == 1) {
        return;
    }

    currentSolution[x][y] = 1;

    solveMaze(maze, currentSolution, result, x - 1, y, size);
    solveMaze(maze, currentSolution, result, x + 1, y, size);
    solveMaze(maze, currentSolution, result, x, y - 1, size);
    solveMaze(maze, currentSolution, result, x, y + 1, size);

    currentSolution[x][y] = 0;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> maze, int size) {
    vector<vector<int>> currentSolution(size, vector<int>(size, 0));
    vector<vector<int>> result;

    solveMaze(maze, currentSolution, result, 0, 0, size);

    return result;
}

int main() {
    int size;
    cout << "Enter the size of the maze: ";
    cin >> size;

    vector<vector<int>> maze(size, vector<int>(size, 0));

    cout << "Enter the maze configuration (0 for blocked, 1 for open):\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> maze[i][j];
        }
    }

    vector<vector<int>> paths = ratInAMaze(maze, size);

    cout << "Number of paths found: " << paths.size() << endl;
    cout << "Paths:\n";
    for (const auto &path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

}
