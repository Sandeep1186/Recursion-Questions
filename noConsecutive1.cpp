#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateStringHelper(int N, string& current, vector<string>& result) {
    if (N == 0) {
        result.push_back(current);
        return;
    }

    // Append '0' to the current string and recurse
    current.push_back('0');
    generateStringUtil(N - 1, current, result);
    current.pop_back();

    // Append '1' to the current string only if the previous character is not '1'
    if (current.empty() || current.back() != '1') {
        current.push_back('1');
        generateStringUtil(N - 1, current, result);
        current.pop_back();
    }
}

vector<string> generateString(int N) {
    vector<string> result;
    string current;
    generateStringHelper(N, current, result);
    return result;
}
int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    vector<string> strings = generateString(N);

    // Display the generated strings
    for (const string& str : strings) {
        cout << str << endl;
    }
}
