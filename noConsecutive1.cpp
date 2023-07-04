#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateStringUtil(int N, string& current, vector<string>& result) {
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
    generateStringUtil(N, current, result);
    return result;
}
