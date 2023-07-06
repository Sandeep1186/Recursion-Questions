#include <iostream>
#include <vector>
using namespace std;

void generateCombinations(string digits, string digitToString[], int currentIndex, string currentCombination, vector<string>& result) {
    if (currentIndex == digits.length()) {
        result.push_back(currentCombination);
        return;
    }
    
    int digit = digits[currentIndex] - '0';
    
    for (int i = 0; i < digitToString[digit].size(); i++) {
        currentCombination.push_back(digitToString[digit][i]);
        generateCombinations(digits, digitToString, currentIndex + 1, currentCombination, result);
        currentCombination.pop_back();
    }
}

vector<string> getCombinations(string digits) {
    string digitToString[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n = digits.length();
    string currentCombination;
    vector<string> result;
    
    if (n == 0) {
        return result;
    }
    
    generateCombinations(digits, digitToString, 0, currentCombination, result);
    
    return result;
}

int main() {
    string input;
    cout << "Enter a string of digits: ";
    cin >> input;
    
    vector<string> combinations = getCombinations(input);
    
    cout << "Possible combinations: ";
    for (string comb : combinations) {
        cout << comb << " ";
    }
    cout << endl;

    return 0;
}
