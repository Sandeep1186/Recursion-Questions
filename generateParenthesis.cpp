#include <iostream>
#include <vector>
using namespace std;

void generateParenthesis(int total, int openCount, int closeCount, string current, vector<string> &result) {
    if (current.size() == total) {
        result.push_back(current);
        return;
    }

    if (openCount > closeCount) {
        generateParenthesis(total, openCount, closeCount + 1, current + ')', result);

        if (openCount < total / 2) {
            generateParenthesis(total, openCount + 1, closeCount, current + '(', result);
        }
    } else {
        generateParenthesis(total, openCount + 1, closeCount, current + '(', result);
    }
}

vector<string> validParenthesis(int n) {
    int total = 2 * n;
    vector<string> result;

    generateParenthesis(total, 0, 0, "", result);

    return result;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<string> parentheses = validParenthesis(n);

    cout << "Valid Parentheses:" << endl;
    for (const auto &p : parentheses) {
        cout << p << endl;
    }

}
