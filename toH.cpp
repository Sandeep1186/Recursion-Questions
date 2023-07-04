#include <iostream>
#include <vector>

using namespace std;

void towerOfHanoiUtil(int n, int source, int auxiliary, int destination, vector<vector<int>>& moves) {
    if (n == 1) {
        moves.push_back({source, destination});
        return;
    }

    towerOfHanoiUtil(n - 1, source, destination, auxiliary, moves);
    moves.push_back({source, destination});
    towerOfHanoiUtil(n - 1, auxiliary, source, destination, moves);
}

vector<vector<int>> towerOfHanoi(int n) {
    vector<vector<int>> moves;
    towerOfHanoiUtil(n, 1, 2, 3, moves);
    return moves;
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    vector<vector<int>> moves = towerOfHanoi(n);

    cout << "Tower of Hanoi moves:\n";
    for (const vector<int>& move : moves) {
        cout << "Move disk from rod " << move[0] << " to rod " << move[1] << endl;
    }

    return 0;
}
