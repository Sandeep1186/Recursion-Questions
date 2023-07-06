#include <iostream>
#include <vector>
using namespace std;

void findFactorCombinations(int currentNumber, int start, int number, vector<int> &factors, vector<vector<int>> &result) {
    if (currentNumber == 1) {
        result.push_back(factors);
        return;
    }

    for (int i = start; i < number; i++) {
        if (currentNumber % i == 0) {
            factors.push_back(i);
            findFactorCombinations(currentNumber / i, i, number, factors, result);
            factors.pop_back();
        }
    }
}

vector<vector<int>> getFactorCombinations(int number) {
    vector<vector<int>> result;
    vector<int> factors;

    findFactorCombinations(number, 2, number, factors, result);
    return result;
}

int main() {
    int input;
    cout << "Enter a number: ";
    cin >> input;
    
    vector<vector<int>> factorCombinations = getFactorCombinations(input);
    
    cout << "Factor Combinations of " << input << ":" << endl;
    for (vector<int> factors : factorCombinations) {
        for (int factor : factors) {
            cout << factor << " ";
        }
        cout << endl;
    }

}
