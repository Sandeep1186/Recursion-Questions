#include <iostream>
#include <vector>
using namespace std;

void combinationSumHelper(vector<vector<int>>& result, int currentIndex, int currentSum,
                          vector<int>& currentList, int target, vector<int>& arr)
{
    if (currentSum == target) {
        result.push_back(currentList);
        return;
    }

    if (currentIndex == arr.size()) {
        return;
    }

    combinationSumHelper(result, currentIndex + 1, currentSum, currentList, target, arr);

    int count = 0;

    while (currentSum <= target) {
        count++;

        currentSum += arr[currentIndex];

        currentList.push_back(arr[currentIndex]);

        combinationSumHelper(result, currentIndex + 1, currentSum, currentList, target, arr);
    }

    while (count--) {
        currentList.pop_back();
    }
}

vector<vector<int>> combSum(vector<int>& arr, int target)
{
    sort(arr.begin(), arr.end());

    vector<vector<int>> result;
    vector<int> currentList;

    combinationSumHelper(result, 0, 0, currentList, target, arr);

    return result;
}

int main()
{
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

    vector<vector<int>> combinations = combSum(arr, target);

    cout << "Combinations that sum up to " << target << ":" << endl;
    for (const auto& comb : combinations) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

}
