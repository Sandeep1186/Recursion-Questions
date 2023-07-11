#include <math.h>
#include <algorithm>

int helper(vector<int>& number, vector<int>& digits, int index = 0) {
    if (index == number.size()) {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < digits.size(); i++) {
        if (number[index] > digits[i]) {
            ans += pow(digits.size(), number.size() - index - 1);
        }
        else if (number[index] == digits[i]) {
            ans += helper(number, digits, index + 1);
            break;
        }
        else {
            break;
        }
    }
    return ans;
}

int possibleNumbers(int n, int m, vector<int>& digits) {
    int d = log10(n) + 1;
    int ans = 0;

    for (int i = 1; i < d; i++) {
        ans += pow(m, i);
    }

    vector<int> number;
    while (n > 0) {
        number.push_back(n % 10);
        n /= 10;
    }
    reverse(number.begin(), number.end());

    int ans1 = helper(number, digits);

    return ans + ans1;
}
