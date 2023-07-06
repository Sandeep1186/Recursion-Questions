#include <iostream>
#include <vector>
using namespace std;

const int MAX_NUM = 30;

void backtrack(vector<int>& combination, int remaining, int current, vector<int>& counter, vector<vector<int>>& result) {
    if (remaining == 0) {
        result.push_back(combination);
        return;
    }

    if (current > MAX_NUM) {
        return;
    }

    while (counter[current] > 0 && remaining >= current) {
        combination.push_back(current);
        counter[current]--;
        remaining -= current;
    }

    while (!combination.empty() && combination.back() == current) {
        backtrack(combination, remaining, current + 1, counter, result);
        combination.pop_back();
        remaining += current;
        counter[current]++;
    }

    backtrack(combination, remaining, current + 1, counter, result);
}

vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    int n = arr.size();
    vector<int> counter(MAX_NUM + 1);

    for (int i = 0; i < n; i++) {
        counter[arr[i]]++;
    }

    vector<vector<int>> result;
    vector<int> combination;

    backtrack(combination, target, 1, counter, result);

    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> combinations = combinationSum2(arr, target);

    cout << "Combinations that sum up to " << target << ":" << endl;
    for (const auto& comb : combinations) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

}
