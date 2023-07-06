#include <iostream>
#include <vector>
using namespace std;

void generateSubsequences(string s, int index, string current, vector<string> &result) {
    if (index == s.length()) {
        if (!current.empty()) {
            result.push_back(current);
        }
        return;
    }

    generateSubsequences(s, index + 1, current, result);

    current.push_back(s[index]);
    generateSubsequences(s, index + 1, current, result);
}

vector<string> subsequence(string str) {
    int n = str.length();
    vector<string> result;
    string current = "";
    generateSubsequences(str, 0, current, result);
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    vector<string> subsequences = subsequence(input);
    
    cout << "Subsequences of " << input << ": ";
    for (string s : subsequences) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
