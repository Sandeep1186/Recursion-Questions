
#include <unordered_map>

#define N 9

bool isValid(int matrix[N][N]) {
    unordered_map<int, int> row[N], column[N], subMatrix[3][3];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 0) {
                continue;
            }

            row[i][matrix[i][j]] += 1;
            column[j][matrix[i][j]] += 1;
            subMatrix[i / 3][j / 3][matrix[i][j]] += 1;

            if (subMatrix[i / 3][j / 3][matrix[i][j]] > 1 || column[j][matrix[i][j]] > 1 ||
                row[i][matrix[i][j]] > 1) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int matrix[N][N], int i, int j) {
    if (i == N - 1 && j == N) {
        return true;
    }

    if (j == N) {
        i++;
        j = 0;
    }

    if (matrix[i][j] != 0) {
        return solveSudoku(matrix, i, j + 1);
    }

    for (int digit = 1; digit <= N; digit++) {
        matrix[i][j] = digit;

        if (isValid(matrix)) {
            if (solveSudoku(matrix, i, j + 1)) {
                return true;
            }
        }

        matrix[i][j] = 0;
    }
    return false;
}

bool isItSudoku(int matrix[9][9]) {
    return solveSudoku(matrix, 0, 0);
}
